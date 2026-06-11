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
const ll MOD=998244353; //1000000007
const ld PI=3.1415926535898;
const ld EPS=1e-9;
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(b==0)return a;return gcd(b,a%b);}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll expo(ll b,ll p,ll m){ll res=1; while(p){if(p&1)res=(res*b)%m; b=(b*b)%m; p>>=1;} return res;}
inline ll modinv(ll a,ll m){return expo(a,m-2,m);}

int n;
ld memo[305][305][305];

ld dp(int a,int b,int c){
	//printf("%d %d %d\n",a,b,c);
	if(a==0&&b==0&&c==0)return 0;
	if(memo[a][b][c])return memo[a][b][c];
	if(a>=305||b>=305||c>=305||a<0||b<0||c<0)return 0;
	ld res=0;
	if(a)res+=dp(a-1,b,c)*(ld)(a)/(ld)(a+b+c);
	if(b)res+=dp(a+1,b-1,c)*(ld)(b)/(ld)(a+b+c);
	if(c)res+=dp(a,b+1,c-1)*(ld)(c)/(ld)(a+b+c);
	return memo[a][b][c]=res+(ld)(n)/(ld)(a+b+c);
}

int main(){
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)scanf("%d",&arr[i]);
	int c[4];memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		c[arr[i]]++;
	}
	printf("%.12Lf",dp(c[1],c[2],c[3]));
}
