#include <bits/stdc++.h>

using namespace std;

inline int ctoi(char c) { if(c < '0' || '9' < c) throw invalid_argument("ctoi error"); return c - '0'; }
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

template <typename T>
inline T gcd(T x, T y){
	if (x <= 0 || y <= 0) throw invalid_argument("gcd error: x <= 0 or y <= 0");
	
	if(x < y) swap(x, y);
	T r = x % y;

	while(r != 0){
		x = y;
		y = r;
		r = x % y;
	}

	return y;
}
template <typename T>
inline T lcm(T x, T y){
	if (x <= 0 || y <= 0) throw invalid_argument("lcm error: x <= 0 or y <= 0");

	return x * y / gcd(x, y);
}

int main(){
	int h, w;
	cin >> h >> w;

	vector<vector<char>> input(h, vector<char>(w));
	int black = 0;
	int white = 0;

	rep(i, h){
		rep(j, w){
			cin >> input[i][j];

			if(input[i][j] == '.') white++;
			else black++;
		}
	}

	// 幅優先探索
	// x y depth
	queue<vector<int>> que;
	que.push(vector<int>{0, 0, 0});

	vector<vector<bool>> check(h, vector<bool>(w, false));
	check[0][0] = true;

	bool flg = false;
	int num;

	while(!que.empty()){
		int x = que.front()[0];
		int y = que.front()[1];
		int depth = que.front()[2];
		que.pop();

		if(x == w - 1 && y == h - 1){
			flg = true;
			num = depth;
			break;
		}

		// 上
		if(0 < y && input[y - 1][x] == '.' && check[y - 1][x] == false){
			que.push(vector<int>{x, y - 1, depth + 1});
			check[y - 1][x] = true;
		}
		// 下
		if(y + 1 < h && input[y + 1][x] == '.' && check[y + 1][x] == false){
			que.push(vector<int>{x, y + 1, depth + 1});
			check[y + 1][x] = true;
		}
		// 左
		if(0 < x && input[y][x - 1] == '.' && check[y][x - 1] == false){
			que.push(vector<int>{x - 1, y, depth + 1});
			check[y][x - 1] = true;
		}
		// 右
		if(x + 1 < w && input[y][x + 1] == '.' && check[y][x + 1] == false){
			que.push(vector<int>{x + 1, y, depth + 1});
			check[y][x + 1] = true;
		}
	}

	if(!flg){
		cout << "-1";
	}
	else{
		cout << white - num - 1;
	}

	return 0;
}