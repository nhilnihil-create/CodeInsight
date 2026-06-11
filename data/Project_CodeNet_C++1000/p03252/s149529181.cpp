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
	string S,T;
	cin >> S >> T;
	map<char, int> mp1,mp2;
	rep(i,S.length()) {
		mp1[S[i]]++;
		mp2[T[i]]++;
	}
	int cnt1=0,cnt2=0;
	vector<int> a1,a2;
	vector<char> b1,b2;
	for(int j=0; j<26; j++) {
		char i = 'a' + j;
		if(mp1[i]) {
			b1.pb(i);
		}
		a1.pb(mp1[i]);
		if(mp2[i]) {
			b2.pb(i);
		}
		a2.pb(mp2[i]);
	}
	bool flag = false;
	/*rep(i,b1.size()) cout << b1[i] << " ";
	cout << endl;
	rep(i,b2.size()) cout << b2[i] << " ";
	cout << endl;

	/*if(b1.size() != b2.size()) {
		cout << "No" << endl;
		return 0;
	}
	sort(b1.begin(),b1.end());
	sort(b2.begin(),b2.end());
	rep(i, b1.size()) {
		if(b1[i] != b2[i]) {
			cout << "No" << endl;
			return 0;
		}
	}*/
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	rep(i,26) {
		if(a1[i] != a2[i]) {
			flag = false;
			break;
		}
		if(i == 25) {flag = true;
		break;}
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;


  return 0;
}
