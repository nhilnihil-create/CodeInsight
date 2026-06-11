#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
// }}} End Header

int main() {
	int n, a, b, c, d;
	cin >> n;
	a = n/1000; n%=1000;
	b= n/100; n%=100;
	c = n/10; n%=10;
	d = n;
	int t[4]={a, b, c, d}; 
	for(int bit=0; bit<(1<<3); bit++){
		int sum = t[0];
		string s=to_string(a);
		for(int i=0; i<3; i++){
			if(bit&(1<<i)){
				sum+=t[i+1];
				s+="+";
			}else{
				sum-=t[i+1];
				s+="-";
			}
			s+=to_string(t[i+1]);
		}
		if(sum == 7){
			cout << s+"=7" << endl;
			return 0;
		}
	}
	return 0;
}