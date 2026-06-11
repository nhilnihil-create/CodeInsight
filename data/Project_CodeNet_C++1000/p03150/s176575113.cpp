#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	string S;
	cin >> S;
	int n = S.length();
	if(S == "keyence") {
		cout << "YES" << endl;
		return 0;
	}
	rep(i,n) for(int j=0; j<n-i; j++) {
		string s = S;
		s.erase(i,j);
		//cout << i << " " << j << " " << s << endl;
		if(s=="keyence") {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;



  return 0;
}
