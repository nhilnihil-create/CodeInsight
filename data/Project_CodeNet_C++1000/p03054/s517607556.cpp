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
	int h,w,n,sr,sc;cin >> h >> w >> n >> sr >> sc;
	string s,t;cin >> s >> t;
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	int l = 0, r = w + 1, u = 0, d = h + 1;
	bool ok = true;
	rep(i,n){
		if(t.at(i) == 'U'){
			if(d <= h) d++;
		}
		else if(t.at(i) == 'D'){
			if(u > 0) u--;
		}
		else if(t.at(i) == 'R'){
			if(l > 0) l--;
		}
		else{
			if(r <= w) r++;
		}
		if(s.at(i) == 'U'){
			u++;
		}
		else if(s.at(i) == 'D'){
			d--;
		}
		else if(s.at(i) == 'L'){
			l++;
		}
		else{
			r--;
		}
		if(r == 1 || l == w || u == h || d == 1 || l >= r || u >= d) ok = false;
	}
	if(sr <= u || sr >= d || sc <= l || sc >= r) ok = false;
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}
