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
	int n = s.size();
	if(s[n-1] == '1' || s[0] == '0'){
		cout << -1 << endl;
		return 0;
	}
	rep(i,n-1){
		if(s[i] != s[n-2-i]){
			cout << -1 << endl;
			return 0;
		}
	}
	s[n-1] = '1';
	queue<int> que;
	rep(i,n){
		if(s[i] == '1') que.push(i+1);
	}
	rep(i,n-1){
		if(i+1 == que.front()) que.pop();
		cout << i+1 << " " << que.front() << endl;
	}
	return 0;
}
