#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int num[10] = {100, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[10050];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	rep(i,m) cin >> a[i];
	sort(a.rbegin(), a.rend());
	rep(i,n+1){
		dp[i] = -1e9;
	}
	dp[0] = 0;
	rep(i,n){
		rep(j,m){
			chmax(dp[i+num[a[j]]], dp[i] + 1);
		}
	}
	vector<int> ans;
	int p = n;
	while(p > 0){
		rep(i,m){
			if(p >= num[a[i]] && dp[p - num[a[i]]] == dp[p] - 1){
				ans.push_back(a[i]);
				p -= num[a[i]];
				break;
			}
		}
	}
	sort(ans.rbegin(), ans.rend());
	for(auto q : ans){
		cout << q;
	}
	cout << endl;
	return 0;
}