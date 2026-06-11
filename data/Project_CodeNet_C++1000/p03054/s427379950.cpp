#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	
	int H,W,N;
	cin >> H >> W >> N;
	int sx,sy;
	cin >> sx >> sy;
	sx--,sy--;
	string s,t;
	cin >> s >> t;
	rep(_,2){
		int L = 0, R = W-1;
		for(int i=N-1;i>=0;i--){
			if(t[i] == 'L') R = min(R+1,W-1);
			if(t[i] == 'R') L = max(L-1,0);

			if(s[i] == 'L') L++;
			if(s[i] == 'R') R--;

			if(L > R){
				cout << "NO" << endl;
				return 0;
			}
		}
		if(sy<L || R<sy){
			cout << "NO" << endl;
			return 0;
		}

		swap(H,W);
		swap(sx,sy);
		for(char& c: s){
			if(c == 'L' || c == 'U') c = 'L'^'U'^c;
			else c = 'R'^'D'^c;
		}
		for(char& c: t){
			if(c == 'L' || c == 'U') c = 'L'^'U'^c;
			else c = 'R'^'D'^c;
		}
	}
	cout << "YES" << endl;
}
