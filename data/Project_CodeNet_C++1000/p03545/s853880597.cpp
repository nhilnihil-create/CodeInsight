#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	rep(i,2)rep(j,2)rep(k,2){
		int num = s[0]-'0';
		num += (i ? (s[1]-'0') : -(s[1]-'0'));
		num += (j ? (s[2]-'0') : -(s[2]-'0'));
		num += (k ? (s[3]-'0') : -(s[3]-'0'));
		if(num == 7){
			cout << s[0];
			cout << (i ? "+" : "-");
			cout << s[1];
			cout << (j ? "+" : "-");
			cout << s[2];
			cout << (k ? "+" : "-");
			cout << s[3];
			cout << "=7" << endl;
			return 0;
		}
	}
	return 0;
}
