//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc023/tasks/agc023_b

//参考：
//https://www.youtube.com/watch?v=8BHBFMrZ8VM

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

LL N;
vector<vector<char>> S;

LL ans = 0;

void solve(){
	//slide:横に何マス分ずらすか
	for(int slide=0;slide<N;slide++){

		// for(int h=0;h<N;h++){
		// 	for(int w=0;w<N;w++){
		// 		cout << S[h][(w+slide)%N];
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		auto symmetric = [&](){
			for(int h=0;h<N;h++){
				for(int w=h+1;w<N;w++){
					if(S[h][(w+slide)%N]!=S[w][(h+slide)%N]) return;
				}
			}
			ans += N;
			return;
		};
		symmetric();
	}
}

int main(){
    cin >> N;
    S = vector<vector<char>>(N,vector<char>(N,0));
    for(int h=0;h<N;h++){
    	for(int w=0;w<N;w++) cin >> S[h][w];
    }

    solve();

	cout << ans << endl;
    return 0;
}