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
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

int N;
int F[101][10];
LL P[101][11];

LL ans = -INF;

void solve(){
	//bit全探索
	for(int bit=1;bit<(2<<9);bit++){
		//店iと、joisinoお姉ちゃんの店のか、ぶった営業時間帯の数
		vector<LL> overlap(N+1,0);
		for(int b=0;b<10;b++){
			//bitのiビット目が立っているなら営業すると決める
			if((bit>>b)&1){
				for(int i=1;i<=N;i++){
					if(F[i][b]) overlap[i]++;
				}
			}
		}
		LL profit = 0;
		for(int i=1;i<=N;i++){
			profit += P[i][overlap[i]];
		}
		ans = max(ans,profit);
	}
}
 
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
    	for(int j=0;j<10;j++){
    		cin >> F[i][j];
    	}
    }
    for(int i=1;i<=N;i++){
    	for(int j=0;j<=10;j++){
    		cin >> P[i][j];
    	}
    }
 
    solve();

	cout << ans << endl;
    return 0;
}