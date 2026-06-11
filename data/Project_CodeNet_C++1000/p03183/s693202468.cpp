#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define pi 3.1415926
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;
const int INF=1000000007;
const int MOD=1000000007;
const int nmax=20123;

int n,w[nmax],s[nmax];
vector<pii> v2;
ll v[nmax],dp[nmax],res;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d%lld",&w[i],&s[i],&v[i]);
        v2.pb({w[i]+s[i],i});
    }
    sort(v2.begin(),v2.end());
    for(int i=0;i<v2.size();++i){
        int pos=v2[i].second;
        for(int j=s[pos];j>=0;--j){
            if(dp[j+w[pos]]<dp[j]+v[pos])
                dp[j+w[pos]]=dp[j]+v[pos];
        }
    }
    for(int i=0;i<=20000;++i)
        if(res<dp[i])
            res=dp[i];
    printf("%lld\n",res);
    return 0;
}
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
