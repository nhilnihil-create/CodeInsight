#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
const int INF=2012345678;
const ll LLINF=4012345678012345678LL;
const ll MOD=1000000007; //998244353; //
const ld PI=3.1415926535898;
const ld EPS=1e-9;
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(b==0)return a;return gcd(b,a%b);}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll expo(ll b,ll p,ll m){ll res=1; while(p){if(p&1)res=(res*b)%m; b=(b*b)%m; p>>=1;} return res;}
inline ll modinv(ll a,ll m){return expo(a,m-2,m);}

int n;
int arr[20][20];
ll memo[1000000];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&arr[i][j]);
	for(int i=0;i<(1<<n);i++){
		vector<int> v;
		int bm=i;
		while(bm&(-bm)){
			v.pb(__builtin_ctz(bm));
			bm-=(bm&(-bm));
		}
		for(int j=0;j<SZ(v);j++){
			for(int k=j+1;k<SZ(v);k++){
				memo[i]+=arr[v[j]][v[k]];
			}
		}
		for(int j=i;j;j=(j-1)&i){
			memo[i]=max(memo[i],memo[j]+memo[i-j]);
		}
	}
	printf("%lld",memo[(1<<n)-1]);
}
