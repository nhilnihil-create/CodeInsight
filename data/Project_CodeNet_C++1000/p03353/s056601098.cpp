#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(v) v.begin(), v.end()
#define revall(v) v.rbegin(), v.rend()
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){ if(y<h && y>=0 && x<w && x>=0) return true; return false; }
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true; } return false; }


bool cmp(string a, string b){
	int k = min(a.size(),b.size());
	rep(i,k){
		if(a.at(i) > b.at(i)) return false;
		if(a.at(i) < b.at(i)) return true;
	}
	if(a.size() < b.size()) return true;
	return false;
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;cin >> s;
	int k;cin >> k;
	int n = s.size();
	set<string> st;
	vector<string> t;
	rep(i,n){
		for(int j = 1; j <= k; j++){
			if(i + j > n) break;
			string u = s.substr(i,j);
			if(st.count(u)) continue;
			st.insert(u);
			t.pb(u);
		}
	}
	sort(t.begin(),t.end(),cmp);
	cout << t.at(k - 1) << endl;
}
