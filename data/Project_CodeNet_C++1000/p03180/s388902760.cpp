#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

/*
3
0 10 20
10 0 -100
20 -100 0
*/
vector<vector<int> >v;
int rabbits;
vector<ll>score;
vector<ll>dp;
ll calscr(int x){
    ll ans=0;
    for(int i=0;i<16;i++){

        if(x&(1<<i)){
            for(int j=i+1;j<16;j++){
                if(x&(1<<j)){
                    ans+=v[i][j];
                }
            }
        }
    }
    return ans;
}
void fillscore(int n){

    for(int i=1;i<(1<<n);i++){
        score[i] = calscr(i);
    }
}
ll maxscore(int rabbits){
    if(dp[rabbits]!=-1){
        return dp[rabbits];
    }
    ll ans=0;
    for(int subset = rabbits;subset !=0;subset =(subset-1)&rabbits){
        ans = max(ans, score[subset] + maxscore(rabbits^subset));
    }
    return dp[rabbits] = ans;
}
void solve(){
    int n;cin>>n;
    score.resize(1<<n,0);
    dp.resize(1<<n,-1);
    dp[0]=0;
    v.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    fillscore(n);
    rabbits = (1<<n) -1;
    cout << maxscore(rabbits)<<"\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);

    cout.precision(10);
    int t=1;//cin>>t;
    while(t--){

        solve();
    }
    return 0;
}
