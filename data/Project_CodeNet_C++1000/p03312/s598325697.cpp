#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <istream>

using namespace std;

typedef pair<int,int> P;
typedef long long ll;

const int maxn = 2e5+10;
ll n,a[maxn];
ll sum[maxn];
ll ans = 1e18;

ll calc(ll a, ll b, ll c){
	return abs(2*sum[b]-sum[a-1]-sum[c]);
}

void work(int a,int b, ll &x, ll &xx){
	int l=a,r=b;
	while(l<r){
		int midl = (l+l+r)/3,midr=(l+r+r+2)/3;
		if(calc(a,midl,b)<calc(a,midr,b)){
			r = midr - 1;
		}else{
			l = midl + 1;
		}
		x = min(sum[b]-sum[l], sum[l]-sum[a-1]);
		xx = max(sum[b]-sum[l], sum[l]-sum[a-1]);
	}
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	for(int i=2;i+2<=n;i++){
		ll x[4]={};
		work(1,i,x[0],x[1]);
		work(i+1,n,x[2],x[3]);
		sort(x,x+4);
		ans = min(ans,x[3]-x[0]);
	}

	cout << ans << endl;

	return 0;
}