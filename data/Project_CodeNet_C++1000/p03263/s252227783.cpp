#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define leftunique(a) {sort((a).begin(),(a).end());(a).erase(unique((a).begin(),(a).end()),(a).end());}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
static const ll INF = 1LL << 60;
//Write From this Line

int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<int>> field(505,vector<int> (505));
	rep(i,h) rep(j,w) cin >> field[i][j];
	int n = 0;
	vector<tuple<int,int,int,int>> ans(0);
	rep(i,h){
		rep(j,w){
			if(i == h-1 && j == w - 1) continue;
			if(field[i][j] % 2){
				int x, y, x_, y_;
				n++;
				y = i, x = j; 
				//右か下に送る
				if(j == w - 1){ // 下に送る
					x_ = j, y_ = i+1;
				} else {
					// 右に送る
					y_ = i; x_ = j+1;
				}
				// ansにぶち込む
				field[y][x] ++;
				field[y_][x_] ++;
				y++, x++, y_++, x_++;
				ans.push_back(make_tuple(y,x,y_,x_));
			} else {
				// 何もしなあい
			}
		}
	}

	// 答えの出力
	cout << n << endl;
	rep(i,n){
		int y, x, y_, x_;
		tie(y, x, y_, x_) = ans[i];
		printf("%d %d %d %d\n",y ,x, y_, x_);
	}
}
