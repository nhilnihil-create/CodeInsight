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
	int n;
	cin >> n;
	vector<int> clock(13, 0);
	clock[0] = 1;
	vector<int> d(n);
	rep(i,n){
		cin >> d[i];
		++clock[d[i]];
	}
	vector<int> v;
	bool flag = true;
	rep(i,13){
		if(clock[i] >= 3){
			cout << 0 << endl;
			return 0;
		}
		if(clock[i] == 2){
			if(i == 0 || i == 12){
				cout << 0 << endl;
				return 0;
			}
			v.push_back(i);
			v.push_back(24-i);
		}
		if(clock[i] == 1){
			if(flag) v.push_back(i);
			else v.push_back(24-i);
			flag = !flag;
		}
	}
	v.push_back(24);
	sort(v.begin(), v.end());
	int ans = 24;
	rep(i,v.size()-1){
		chmin(ans, v[i+1] - v[i]);
	}
	cout << ans << endl;
	return 0;
}