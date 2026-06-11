#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int h, w;
vector<string> fie(50);

const int di[] = {-1,0,0,1};
const int dj[] = {0,-1,1,0};
bool check(int sy, int sx, int k){
	if(sy + di[k] < 0 || sx + dj[k] < 0) return false;
	if(sy + di[k] >= h || sx + dj[k] >= w) return false;
	int ny = sy + di[k];
	int nx = sx + dj[k];
	if(fie[ny][nx] == '#') return true;
	else return false;
}
int main()
{
	cin >> h >> w;
	rep(i, h)cin>>fie[i];

	// 全てのマスに対して、上下左右の4マスに黒があるかみる。
	rep(i,h){
		rep(j,w){
			bool ng = true;
			if(fie[i][j] == '.'){
				continue;
			} else {
				rep(k,4){
					if(check(i,j,k)){
						// ok; 4回のうちどれかしらが通ればいい。
						ng = false;
					}	
				}
				if(ng) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
}
