#include<bits/stdc++.h>
using namespace std;
//#define int long long
//ask the right questions.  

//we have N vertices and M edges

// dp[i] means max length possible to reach vertex i (~item and not index) 
int dp[100001];


//LOGIC: if you are at vertex i then you could have reached there from finite incoming edges ending at i.
//then dp[i] is the maximum of (the maximum length to reach the node connecting i) for all incoming edges 
//and then we add 1 to connect i. 
//Our answer is maximum of dp[i] for all i.

//stores in a vector, all the edges which end at the vertex(KEY) 
map<int,vector<int>> edgesendsat;       


//since the dp equation is not exactly bottom up we use some sort of memoization.
//the code is identical and will go up a path until it finds the base case ie no incoming vertex at vertex i.
//the logic remains same as the main dp loop though.
void calculate(int i)
{
    vector<int> v = edgesendsat[i];
    int ans=0;
    for(int j=0;j<v.size();j++) 
    {
        //again if dp[v[j]]=-1 then further branch out to calculating that dp[v[j]]
        if(dp[v[j]]==-1)
            calculate(v[j]); 
        ans = max(ans, dp[v[j]]);    
    }
    dp[i] = 1 + ans;
}


int main()
{
    int N,M;
    cin >> N >> M;
    int x,y;
    for(int i=0;i<M;i++) 
    {
        cin >> x >> y;
        if(edgesendsat.find(y)!=edgesendsat.end()) 
        {
            edgesendsat[y].push_back(x);
        }
        else 
        {
            edgesendsat.insert({y,{x}});
        }
    }

    //trivial case : since vertex numbering starts from 1
    dp[0]=0;

    //base case: 
    for(int i=1;i<=N;i++) {
        dp[i]=-1;                                           //by default for memoization 
        if(edgesendsat.find(i)==edgesendsat.end())           
            dp[i]=0;    //means you cannot reach this vertex ie no incoming 
                        //edges to this vertex (may have outgoing edges though)
    }


    for(int i=1;i<=N;i++)
     {
        //we now construct our dp. 
        //we dont do it for no-incoming-edge vertices (base case) as they dont have any [KEY] in the map. 
        if(edgesendsat.find(i)!=edgesendsat.end()) 
        {
            vector<int> v = edgesendsat[i];
            int ans=0;
            for(int j=0;j<v.size();j++) 
            {
                //if dp[v[j]]=-1 then branch to calculating that dp[v[j]]
                //since we go in increasing i, all dp[k<i] have been updated (or are zero which were skipped
                //due to base case). Hence if we found a vertex in v whose state we have not seen before ie it
                //has v[j]>=i then we branch out to calculate and update it first.
                if(dp[v[j]]==-1)
                    calculate(v[j]); 
                ans = max(ans, dp[v[j]]);    
            }
            dp[i] = 1 + ans;
        }
    }
    

    //main answer   
    int ansterm=0;
    for(int i=1;i<=N;i++) {
        ansterm = max(ansterm, dp[i]);
    }
    cout << ansterm <<endl;

    return 0;
}

