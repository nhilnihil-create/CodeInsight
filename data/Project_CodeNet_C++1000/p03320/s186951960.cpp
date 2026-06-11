#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

ll sq(ll num) { return num*num; }
ll mod_pow(ll x, ll n) {
	if (n == 0)return 1;
	if (n == 1)return x%MOD;
	ll res = sq(mod_pow(x, n / 2));
	res %= MOD;
	if (n % 2 == 1) {
		res *= x;
		res %= MOD;
	}
	return res;
}

ll k;

double S(ll i){
	ll res = 0;
	while(i > 0){
		res += i%10;
		i /= 10;
	}
	return res;
}

bool check(ll i,ll j){
	return i*S(j) > j*S(i);
}

int main(){
	cin >> k;
	vector<ll> buf;
	vector<ll> ans;
	ll b = 1;
	rep(i,15){
		ll bb = b - 1;
		FOR(j,1,300){
			buf.push_back(b*j + bb);
			// cout << b*j+bb << endl;
		}
		b *= 10;
	}
	sort(ALL(buf));

	rep(i,buf.size()){
		FOR(j,i+1,buf.size()){
			if(check(buf[i],buf[j]) || buf[i] == buf[j])break;
			if(j == buf.size()-1){
				// cout << buf[i] << endl;
				ans.push_back(buf[i]);
			}
		}
	}
	rep(i,min(k,(ll)ans.size()))cout << ans[i] << endl;

	// double M = 0;
	// FOR(i,1,1000000){
	// 	double a = (double)i/calc(i);
	// 	double b = (double)(i+1)/calc(i+1);
	// 	if(a - b < EPS  && M - a < EPS){
	// 		cout << i << " " << a << endl;
	// 		M = max(M,a);
	// 	}
	// }
	// return 0;
	// rep(i,100000){
	// 	cout << i << " " << (double)i/calc(i) << endl;
	// }
	// return 0;
	// vector<string> ans;
	// FOR(i,1,10){
	// 	string s;
	// 	s += ((char)('0'+i));
	// 	ans.push_back(s);
	// }
	// // string t = "9";
	// // FOR(i,1,10){
	// // 	string s;
	// // 	s = ((char)('0'+i)) + t;
	// // 	ans.push_back(s);
	// // }
	// FOR(i,1,10){
	// 	string s = "";
	// 	rep(j,i)s += "9";
	// 	FOR(j,1,18+1){
	// 		string tt = "";
	// 		if(j/10 != 0)tt += (char)('0' + j/10);
	// 		tt += (char)('0' + j%10);
	// 		tt += s;
	// 		ans.push_back(tt);
	// 	}
	// }
	// rep(i,min(k,(ll)ans.size()))cout << ans[i] << endl;
	
}