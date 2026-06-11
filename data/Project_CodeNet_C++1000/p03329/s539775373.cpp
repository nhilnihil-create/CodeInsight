#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=2e5+100;
ll n,V;
ll v[100],w[100];
ll ansv,answ,ans;

int dp[N];
vector<int>ve;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    ve.push_back(1);
    int k=6;
    for(int i=0;i<=n;i++) dp[i]=i;
    while(k<=n){
         ve.push_back(k);
         k*=6;
    }
    k=9;
    while(k<=n){
        ve.push_back(k);
        k*=9;
    }

    for(int i=0;i<ve.size();i++){
        for(int j=ve[i];j<=n;j++){
            dp[j]=min(dp[j],dp[j-ve[i]]+1);
        }
    }
    cout<<dp[n]<<endl;
}
