#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(123456789)
#define LINF (long long int)(123456789012345678)
//#define ARRAY(type,n) (type *)malloc(sizeof(type)*n)
template<typename T>
T* ARRAY(int n){
	(T*)malloc(sizeof(T)*n);
}
template<typename T>
T** ARRAY2(int m,int n){
	T** type = (T**)malloc(sizeof(T*)*m);
	for(int i=0;i<m;i++){
		type[i]=(T*)malloc(sizeof(T)*n);
	}
	return type;
}

class info{
public:
	ll x;
	ll y;
	ll h;

};

bool cmp(info a, info b){
	if(a.h == 0){
		return false;
	}
	if(b.h == 0){
		return true;
	}
	if(a.x == b.x){
		return a.y < b.y;
	}
	return a.x < b.x;
	
}

//first:base
pair<ll,ll> nibun(ll sum[], int first, int last){
	ll kijun = (sum[last] - sum[first])/2;
	ll base = sum[first];
	ll base2 = sum[last];
	first++;
	int now = (first + last)/2;
	while(last - first > 1){
		if(sum[now] - base > kijun){
			last = now;

		}else{
			first = now;
		}
		now = (first + last)/2;
	}
	pair<ll,ll> retval;
	ll down1 = sum[now] - base;
	ll up1 = base2 - sum[now];
	ll down2 = sum[now+1] - base;
	ll up2 = base2 - sum[now+1];
	if(abs(down1-up1) <= abs(up2-down2)){
		retval.first = down1;
		retval.second = up1;
	}else{
		retval.first = down2;
		retval.second = up2;
	}
	return retval;
}

int main(void){
	int n;
	cin>>n;
	ll a[200003];
	ll sum[200003];
	sum[0] = 0;
	rep(i,n){
		cin>>a[i];
		sum[i+1] = sum[i] + a[i];
	}

	ll ans = LINF;
	for(int i=2; i<=n-2; i++){
		ll b = nibun(sum, 0, i).first;
		ll c = nibun(sum, 0, i).second;
		ll d = nibun(sum, i, n).first;
		ll e = nibun(sum, i, n).second;
		ll minimum = min(b,min(c,min(d,e)));
		ll maximum = max(b,max(c,max(d,e)));
		//cout<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<minimum<<" "<<maximum<<endl;
		ans = min(ans,maximum - minimum);
	}

	cout<<ans<<endl;
	return 0;
}