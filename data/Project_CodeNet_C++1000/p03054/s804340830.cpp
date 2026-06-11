#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	int h, w; cin >> h >> w; 
	int n; cin >> n; 
	int si, sj; cin >> si >> sj;
	string s, t; cin >> s >> t;

	// 右で落とす
	int pos = sj;
	rep(i,n){
		if(s[i] == 'R') pos ++;
		if(pos > w){
			cout << "NO" << endl;
			return 0;
		}
		if(t[i] == 'L') {
			if(pos > 1)	pos--;
		}
	}
	pos = sj;
	rep(i,n){
		if(s[i] == 'L') pos--;
		if(pos < 1){
			cout << "NO" << endl;
			return 0;
		}
		if(t[i] == 'R') {
			if(pos < w) pos++;
		}
	}
	pos = si;
	rep(i,n){
		if(s[i] == 'U') pos--;
		if(pos < 1){
			cout << "NO" << endl;
			return 0;
		}
		if(t[i] == 'D') {
			if(pos < h) pos ++;
		}
	}
	pos = si;
	rep(i,n){
		if(s[i] == 'D') pos++;
		if(pos > h){
			cout << "NO" << endl;
			return 0;
		}
		if(t[i] == 'U'){
			if(pos > 1) pos--;
		}
	}
	cout << "YES" << endl;
}
