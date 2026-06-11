//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/aising2019/tasks/aising2019_c

//参考
//https://betrue12.hateblo.jp/entry/2019/01/13/030527

//マスをグラフの頂点、色の異なるマス同士に辺がかかっている
//森だとみなすと考えやすい

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
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL H,W;
string S[1000];

LL ans = 0;

void solve(){
	int white_remain = 0;
	queue<pair<int,int>> q;
	for(int h=0;h<H;h++){
		for(int w=0;w<W;w++){
			if(S[h][w]=='.') white_remain++;
			else q.push(pair<int,int>(h,w));
		}
	}

	for(ans=0;white_remain>0;ans++){
		int n = q.size();
		for(int i=0;i<n;i++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			int ret = 0;
			if(y+1<H){
				if(S[y+1][x]=='.'){
					S[y+1][x] = '#';
					ret++;
					q.push(pair<int,int>(y+1,x));
				}
			}
			if(y-1>=0){
				if(S[y-1][x]=='.'){
					S[y-1][x] = '#';
					ret++;
					q.push(pair<int,int>(y-1,x));
				}
			}
			if(x+1<W){
				if(S[y][x+1]=='.'){
					S[y][x+1] = '#';
					ret++;
					q.push(pair<int,int>(y,x+1));
				}
			}
			if(x-1>=0){
				if(S[y][x-1]=='.'){
					S[y][x-1] = '#';
					ret++;
					q.push(pair<int,int>(y,x-1));
				}
			}
			white_remain -= ret;
		}
	}
}
 
int main(){
    cin >> H >> W;
    for(int h=0;h<H;h++){
    	cin >> S[h];
    }
 
    solve();

	cout << ans << endl;
    return 0;
}