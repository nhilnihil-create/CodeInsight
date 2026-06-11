#include <bits/stdc++.h>
using namespace std;
//#define MOD 100000007
long long N;
long long M;
int k;
using Graph = vector<vector<int>>;
vector<int> color(100000,0);
vector<bool> used(100000,false);
//vector<bool> ans(100000,false);

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,-1,0,1};
int ans = 0;

bool bfs(Graph &data, int t,int col)
{
    color[t] = col;
    
    for(int i = 0;i<data[t].size();i++)
    {
        if(color[data[t][i]] != 0)
        {
            if(color[data[t][i]] == col)
            {
                color[t] = 0;
                return false;
            }
            else
            {
                continue;
            }
        }
        else
        {
            if(!bfs(data,data[t][i],col*-1)) return false;
        }
    }
    return true;
}
int main()
{
    cin >> N ;
    cin >> M;
    
    Graph data(N);
    
    for(int i = 0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        data[a].push_back(b);
        data[b].push_back(a);
    }
    
   
    if(bfs(data,0,1))
    {
        long long B = 0;
        long long  W = 0;
        for(int i=0;i<N;i++)
        {
            if(color[i] == 1)
            {
                B++;
            }
            else W++;
            
        }
        cout << B * W - M << endl;
    }
    else
    {
        cout << (N-1)*N/2 - M << endl;
    }
    
    
    //cout << ans << endl;
    
    return 0;
}