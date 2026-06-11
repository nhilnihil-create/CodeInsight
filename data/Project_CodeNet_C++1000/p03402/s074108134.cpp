//g++ -std=c++14 test.cpp -o test.out
//URL
//https://atcoder.jp/contests/abc092/tasks/arc093_b

//参考：https://pitsbuffersolution.com/compro/atcoder/arc093d.php

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

LL A,B;
 
vector<vector<char>> ans;

void solve(){
	ans = vector<vector<char>>(100,vector<char>(100));
	for(int h=0;h<50;h++){
		for(int w=0;w<100;w++) ans[h][w] = '#';
	}
	for(int h=50;h<100;h++){
		for(int w=0;w<100;w++) ans[h][w] = '.';
	}
	//この時点でansには上半分が全部#(黒),下半分が全部.(白)のグリッドが生成される
	//その連結成分は白黒それぞれ1,1

	//上半分の黒で塗り潰された箇所に白を1マスずつ塗っていく
	//この時(0,0)を始点として、上下左右に白が隣り合わないように
	//1マスずつ塗っていく

	//最大数白を塗った時白の連結成分の数は
	//グリッド全体の下半分の白の連結成分も含めて
	//50*24 + 1 = 1201個作れ、A<=500なことを考えると十分
	//黒の連結成分についても同様
	[](){
		for(int h=0;h<50;h+=2){
			for(int w=0;w<100;w+=2){
				if(A == 1) return;
				ans[h][w] = '.';
				--A;//白のあと必要な連結成分数を減らす
			}
		}
	}();
	[](){
		for(int h=99;h>50;h-=2){
			for(int w=0;w<100;w+=2){
				if(B == 1) return;
				ans[h][w] = '#';
				--B;//黒のあと必要な連結成分数を減らす
			}
		}
	}();
}

int main(){
    cin >> A >> B;
 
    solve();

    cout << ans.size() << " " << ans[0].size() << endl;
    for(int h=0;h<ans.size();h++){
    	for(int w=0;w<ans[0].size();w++) cout << ans[h][w];
    		cout << endl;
    }
    return 0;
}