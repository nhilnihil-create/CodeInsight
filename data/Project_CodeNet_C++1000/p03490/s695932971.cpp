#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;
    int xs=0,ys=0;
    int state=-1;
    vector<int> xv,yv;
    for(auto c:s){
        if(c=='T'){
            if(xs) xv.push_back(xs);
            if(ys) yv.push_back(ys);
            xs=ys=0;
            state=(state+1)%2;
        }
        else{
            switch(state){
                case -1:{
                    x--; break;
                }
                case 0:{
                    ys++; break;
                }
                case 1:{
                    xs++; break;
                }
            }
        }
    }
    if(xs) xv.push_back(xs);
    if(ys) yv.push_back(ys);
    
    auto knapsack=[](const vector<int>& v,int tar){
        int n=v.size();
        const int OFFSET=8000+5;
        const int SIZE=OFFSET*2+5;;
        vector<vector<int>> dp(2,vector<int>(SIZE,0));
        dp[0][OFFSET]=true;
        for(int i=0;i<n;i++){
            fill(dp[(i+1)&1].begin(),dp[(i+1)&1].end(),0);
            for(int j=0;j<SIZE;j++){
                if(j+v[i]<SIZE) dp[(i+1)&1][j+v[i]]|=dp[i&1][j];
                if(j-v[i]>=0) dp[(i+1)&1][j-v[i]]|=dp[i&1][j];
            }
        }
        return dp[n&1][OFFSET+tar];
    };
    cout<<(knapsack(xv,x) && knapsack(yv,y) ? "Yes" : "No")<<endl;
    
    return 0;
}