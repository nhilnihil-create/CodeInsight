#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 
ll A(ll x){
    if(x>=0)return x;
    else return -x;
}
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}
 
const double PI=3.14159265358979323846;



ll kaijo[2000010];
void init() {
	kaijo[0] = 1;
	for (ll i = 1;i < 2000010;i++)kaijo[i] = (kaijo[i - 1] * i) % N;
}
 
ll inv(ll x,ll power) {
	ll res = 1;
	ll k = power;
	ll y = x;
	while (k) {
		if (k & 1)res = (res*y) % N;
		y = (y%N*y%N) % N;
		k /= 2;
	}
	return res;
}
 
ll Comb(ll n, ll k) {
	if (n < 0 || k < 0 || (n - k) < 0)return 0;
	ll b = kaijo[n];
	ll c = kaijo[n - k];
	ll d = kaijo[k];
	ll cd = (c*d) % N;
	return ((b%N)*(inv(cd,N-2)) % N) % N;
}

int main(void){
    ll x,y,z,k;
	cin>>x>>y>>z>>k;
	vector<ll>a(x),b(y),c(z),d,ans;
	for(int i=0;i<x;i++)cin>>a[i];
	for(int i=0;i<y;i++)cin>>b[i];
	for(int i=0;i<z;i++)cin>>c[i];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			d.push_back(a[i]+b[j]);
		}
	}
	sort(d.begin(),d.end(),greater<ll>());
	sort(c.begin(),c.end(),greater<ll>());
	ll L = min(k,(ll)d.size());
	for(int i=0;i<L;i++){
		for(int j=0;j<z;j++){
			ans.push_back(d[i]+c[j]);
		}
	}
	sort(ans.begin(),ans.end(),greater<ll>());
	for(int i=0;i<k;i++)cout<<ans[i]<<endl;
    return 0;
}