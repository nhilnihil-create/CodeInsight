#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){ if(y<h && y>=0 && x<w && x>=0) return true; return false; }
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true; } return false; }






int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;cin >> s;
	int n = s.size();
	bool ok = true;
	rep(i,n / 2){
		if(s.at(i) != s.at(n - 1 - i)){
			ok = false;
			break;
		}
	}
	if(ok){
		cout << 0 << endl;
		return 0;
	}
	string t = "";
	rep(i,n){
		if(s.at(i) != 'x') t += s.at(i);
	}
	int m = t.size();
	ok = true;
	rep(i,m / 2){
		if(t.at(i) != t.at(m - 1 - i)){
			ok = false;
			break;
		}
	}
	if(!ok){
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	int i = 0, j = n - 1;
	while(i < j){
		int cnt1 = 0, cnt2 = 0;
		while(s.at(i) == 'x'){
			i++;
			cnt1++;
		}
		while(s.at(j) == 'x'){
			j--;
			cnt2++;
		}
		if(i > j) break;
		ans += abs(cnt1 - cnt2);
		i++;
		j--;
	}
	cout << ans << endl;
}
