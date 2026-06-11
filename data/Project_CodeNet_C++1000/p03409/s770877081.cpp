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

LL N;
vector<set<LL>> red;//x座標がiであるような赤い点の集合をred[i]とおく
vector<set<LL>> blue;//blue[a]内の要素が降順になるよう設定
 
LL ans = 0;

void solve(){
	//条件のきついものからみる
	for(int blue_x=0;blue_x<=2*N-1;blue_x++){//青い点のx座標が0<=blue_x<=2*N-1まで調べる
		//青い点のx座標がblue_xのもののうち、y座標が小さいものから見ていく
		for(auto blue_y_iter=blue[blue_x].begin();blue_y_iter!=blue[blue_x].end();blue_y_iter++){
			LL blue_y = *(blue_y_iter);
			//x座標がblue_x未満の赤い点を,x座標の大きいものから調べ、
			//その中で最もy座標が大きいものを採用
			pair<LL,LL> selected_red(-1,-1);
			for(int red_x=blue_x-1;red_x>=0;red_x--){
				//ギリギリy座標がblue_y未満になるものを選んでくる
				auto iter = red[red_x].lower_bound(blue_y);
				if(iter==red[red_x].begin()) continue;
				iter--;
				LL red_y = *iter;
				if(selected_red.second<red_y){
					selected_red = pair<LL,LL>(red_x,red_y);
				}
			}
			if(selected_red.first==-1) continue;
			//printf("red(%d,%d)とblue(%d,%d)をペアに\n",selected_red.first,selected_red.second,blue_x,blue_y);
			red[selected_red.first].erase(selected_red.second);
			ans++;
		}
	}
}

int main(){
    cin >> N;
    red = vector<set<LL>>(2*N);
    blue = vector<set<LL>>(2*N);
    for(int i=0;i<N;i++){
    	LL a,b;cin >> a >> b;
    	red[a].insert(b);
    }
    for(int i=0;i<N;i++){
    	LL a,b;cin >> a >> b;
    	blue[a].insert(b);
    }
 
    solve();

    cout << ans << endl;
    return 0;
}