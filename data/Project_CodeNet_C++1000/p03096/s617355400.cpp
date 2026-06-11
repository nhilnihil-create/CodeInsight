#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define pr(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define nl printf("\n")
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,st,en) for(i=st;i<=en;i++)
#define repv(i,en,st) for(i=en;i>=st;i--)
#define fout cout<<fixed<<setprecision(7)
#define bi(n) __builtin_popcount(n)
#define bil(n) __builtin_popcountll(n)


typedef long long ll;
typedef pair<int,int> pii;
const int N = 200010;
ll mod = 1e9+7;
ll fmod(ll b,ll exp){
    ll res =1;
    while(exp){if(exp&1ll)res=(res*b)%mod;
    b =(b*b)%mod;exp/=2ll;
    }
    return res;
}

int A[N],buc[N],pre[N];
ll dp[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,i,j,k,x,q;
    int t=1;
    cin>>n;
    memset(buc,-1,sizeof(buc));
    rep(i,1,n){
        cin>>A[i];
        pre[i]= buc[A[i]];
        buc[A[i]]=i;
    }
    dp[0]=1;
    rep(i,1,n){
        dp[i]= (dp[i]+ dp[i-1])%mod;
        if(pre[i]==-1 || pre[i]==i-1)continue;
        dp[i] = (dp[i]+dp[pre[i]])%mod;
    }
    cout<<dp[n]<<"\n";


    
    return 0;
}
