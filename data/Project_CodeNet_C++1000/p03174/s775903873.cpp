#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll dp[25][2100000];
bool mat[25][25];
unsigned long long int popcount(unsigned long long int n){
    if(n==0) return 0;
    return 1+popcount(n&(n-1));
}
void solve(ll caseno){
	ll i,j,k,n;
    mset(mat,0);
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=0;j<n;j++) cin>>mat[i][j];
    }
    const ll MX = pow(2,n)-1;
    for(i=0;i<=MX;i++) dp[0][i]=0;
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        //i is the man
        for(j=0;j<=MX;j++){
            //j is the mask
            dp[i][j]=0;
            ll ppc=popcount(j);
            //cout<<j<<' '<<ppc<<endl;
            if(ppc==i){
                for(k=0;k<n;k++){
                    //k is the woman to be matched
                    if( (j&(1<<k)) && mat[i][k]) dp[i][j]+=dp[i-1][j^(1<<k)];
                    dp[i][j]%=MOD;
                }
            }
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][MX];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
