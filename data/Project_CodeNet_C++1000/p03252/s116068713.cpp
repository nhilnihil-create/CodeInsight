#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string s, t;

int main(void){
	cin >> s >> t;
	vector<lli> cs(26), ct(26);
	for(auto si : s) cs[si-'a']++;
	for(auto ti : t) ct[ti-'a']++;
	sort(cs.begin(), cs.end());
	sort(ct.begin(), ct.end());
	rep(i, 26){
		if(cs[i] != ct[i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
