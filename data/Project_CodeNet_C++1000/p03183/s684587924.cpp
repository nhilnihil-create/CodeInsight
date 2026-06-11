#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 3;

struct box{
	int w, s, val;
};

bool cmp(box a, box b){
	return a.w + a.s < b.w + b.s;
}

ll dp[20010]; //dp[i] menyatakan jumlah value maksimal apabila total weight adalah i

int main(){
	int n,i,j;
	box a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&a[i].w, &a[i].s, &a[i].val);
	}

	sort(a,a+n, cmp);

	for(i=0;i<n;i++){
		int maksBerat = a[i].s;
		for(j=maksBerat;j>=0;j--){
			dp[j+a[i].w] = max(dp[j+a[i].w], dp[j] + a[i].val);
		}
	}
	ll maks = 0;
	for(i=0;i<20001;i++){
		maks = max(maks, dp[i]);
	}
	printf("%lld\n",maks);

	return 0;
};