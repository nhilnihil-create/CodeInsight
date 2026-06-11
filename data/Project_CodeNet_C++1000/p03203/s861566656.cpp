#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isIn(x,y,h,w) (x >= 0 && x < h && y >= 0 && y < w)

#define int long long
//using ll = long long;
using P = pair<int,int>;

ostream &operator<<(ostream &os,const P &p){ return os << "(" << p.first << "," << p.second << ")"; }

template<class T> T &chmin(T &a,const T &b){ return a = min(a,b); }
template<class T> T &chmax(T &a,const T &b){ return a = max(a,b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

vector<int> vec[200010];

bool isExist(int x,int y){
	int ind = lower_bound(all(vec[y]),x) - vec[y].begin();
	return vec[y][ind] == x;
}

signed main(){
	int h,w,n;
	cin >> h >> w >> n;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y; x--;y--;
		vec[y].push_back(x);
	}
	for(int i = 0;i < w;i++){
		vec[i].push_back(h);
		sort(all(vec[i]));
	}
	int mi = INF,pos = 0;
	for(int i = 0;i < w;i++){
		int ind = lower_bound(all(vec[i]),pos) - vec[i].begin();
		chmin(mi,vec[i][ind]);
		if(i == w - 1) break;
		if(isExist(pos + 1,i)){
			cout << mi << endl;
			return 0;
		}
		pos++;
		while(isExist(pos,i + 1)){
			if(isExist(pos + 1,i)){
				cout << mi << endl;
				return 0;
			}
			pos++;
		}
	}
	cout << mi << endl;
}