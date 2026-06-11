//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,C;
LL D[31][31];
LL c[501][501];
 
LL ans = INF;

void solve(){
	//(x+y)%3 = i%3が0,1,2の各場合について
	//j色(1<=j<=C)で塗られている数を
	//color[i%3][j]とする
	vector<vector<LL>> color(3,vector<LL>(C+1,0));
	for(int y=1;y<=N;y++){
		for(int x=1;x<=N;x++){
			color[(y+x)%3][c[y][x]]++;
		}
	}
	//余りが0,1,2それぞれのマスについてそれぞれ
	//色i,j,kを割り当てる場合を考える
	for(int i=1;i<=C;i++){
		for(int j=1;j<=C;j++){
			for(int k=1;k<=C;k++){
				//3つ選定する色はそれぞれ異なっている必要がある
				if(i==k || j==k || i==j) continue;
				LL sum = 0;
				//余りが0,1,2それぞれのマスの、色cであるものを色iに塗り替えるコスト
				for(int c=1;c<=C;c++) sum += (D[c][i])*color[0][c];
				for(int c=1;c<=C;c++) sum += (D[c][j])*color[1][c];
				for(int c=1;c<=C;c++) sum += (D[c][k])*color[2][c];
				ans = min(ans,sum);
			}
		}
	}
}

int main(){
    cin >> N >> C;
    for(int i=1;i<=C;i++){
		for(int j=1;j<=C;j++) cin >> D[i][j];
	}
	for(int y=1;y<=N;y++){
		for(int x=1;x<=N;x++) cin >> c[y][x];
	}
 
    solve();
 
    cout << ans << endl;
    return 0;
}