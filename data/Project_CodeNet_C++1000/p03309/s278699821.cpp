#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;


int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	rep(i, n)	{
		ll t;
		cin >> t;
		t = t - (i + 1);
		a[i] = t;
	}
	vector<ll> b = a;
	sort(b.begin(), b.end());
	ll med;
	if(n % 2){
		med = b[n / 2];
	} else {
		med = (b[n / 2] + b[n / 2 - 1]) / 2;
	}
	ll ans = 0;
	rep(i, n){
		ans += abs(a[i] - med);
	}
	cout << ans << endl;
}