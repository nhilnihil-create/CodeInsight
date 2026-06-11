#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) {}
#endif






int main(){
	string s;
	cin >> s;
	int len = SZ(s);
	
	ll op = 0;
	ll ct = 0;
	rep(i,len){
		if ( s[i] == 'W' ){
			op += i;
			ct++;
		}
	}
	
	cout << op - (ct-1)*ct/2 << endl;
	
	return 0;
}


