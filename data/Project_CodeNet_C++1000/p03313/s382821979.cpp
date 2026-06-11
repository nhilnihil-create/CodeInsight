//I read the news today, oh boy
//About a lucky man who made the grade
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ll((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define roF(i,a,b) for(ll i = ll(a); i >= ll(b); i--)
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll N=1<<19;

int n;
ll a[N];
ll dp[N];
ll may, may2;

int V[N];
int tam;

void getsubmasks(int mask, int i = 0, int sub=0){
	if(i==tam){
		if(a[sub]>may){
			may2=may;
			may=a[sub];
		}else if(a[sub]>may2) may2=a[sub];
		return;
	}
	getsubmasks(mask, i+1, sub);
	getsubmasks(mask, i+1, sub | (1<<V[i]));
}

int main(){
	scanf("%d",&n);
	int tot= 1<<n;
	For(i,0,tot) scanf("%lld",&a[i]);
	For(msk,1,tot){
		tam=0;
		For(j,0,n)
			if((msk>>j)&1) V[tam++]=j;
		may = -1;
		may2=-1;
		getsubmasks(msk);
		dp[msk] = may+may2;
	}
	For(i,1,tot){
		dp[i]=max(dp[i],dp[i-1]);
		printf("%lld\n",dp[i]);
	}
	return 0;
}

