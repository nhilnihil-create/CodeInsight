#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << "   ";
		}
		cout << endl;
	}
}


const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};
typedef pair<int, int> P;
const int INF = 100100100;
int main(){//
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for(int i=0; i<(int)s.size(); i++) cin >> s[i];
    //for(int i=0; i<H; i++) cin >> s[i];
    //BFSして最短経路を見つけ，　
    //そのあと，黒く塗れるマスを数える
    vector<vector<int>> grid(H, vector<int>(W, INF));
    grid[0][0] = 0;
    queue<P> q;
    q.push(P(0, 0));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int next_y = y + dy[dir];
            int next_x = x + dx[dir];
            if(next_y < 0 || H <= next_y) continue;
            if(next_x < 0 || W <= next_x) continue;
            if(s[next_y][next_x] == '#') continue;
            if(grid[next_y][next_x] != INF) continue;
            grid[next_y][next_x] = grid[y][x] + 1;
            q.push(P(next_y, next_x));
        }
    }

    //cout << " BFS is completed ! " << endl;
    int ans = 0;
    if(grid[H-1][W-1] == INF){
        ans = -1;
        cout << ans << endl;
        return 0;
    }
    int min_step = grid[H-1][W-1];
    //gridの中に同じ値が入っていたら数える為のフラグ
    vector<bool> is_double(min_step+5, false); 
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(grid[i][j] > min_step && s[i][j] == '.'){
                ans++;
                continue;
            }
            if(s[i][j] == '#') continue;
            if(is_double[grid[i][j]] == true){
                ans++;
                continue;
            }
            is_double[grid[i][j]] = true;

        }
    }

    cout << ans << endl;



}
