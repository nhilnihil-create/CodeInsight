#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int n, m;
	cin >> n;
	vector<string> s(n);
	rep(i,n) cin >> s.at(i);
	cin >> m;
	vector<string> t(m);
	rep(i,m) cin >> t.at(i);
	int ans = 0;
	rep(i,n){
		int cnt = 0;
		rep(j,n){
			if(s.at(i)==s.at(j)){
				cnt++;
			}
		}
		rep(j,m){
			if(s.at(i)==t.at(j)){
				cnt--;
			}
		}
		
		ans = max(ans,cnt);
	}
	cout << ans << endl;

	return 0;
}
