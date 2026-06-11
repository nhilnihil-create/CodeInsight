//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc109/tasks/abc109_d

//参考
//https://www.hamayanhamayan.com/entry/2018/09/09/004851

//まず各行についてできるだけ右へ右へずらしていく
//そうすると各行の一番右端が奇数かそうでないか、といった状態が完成する
//今度は縦に見ていって下へ下へずらしていく
//最終的に一番右下の1マスが奇数かそうでないか、といった状態が出来上がる

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
LL a[500][500];

//コインをfirstからsecondへ移動する操作
vector<pair<pair<LL,LL>,pair<LL,LL>>> ans;

void add_move(LL y,LL x,LL to_y,LL to_x){
	ans.push_back(pair<pair<LL,LL>,pair<LL,LL>>(pair<LL,LL>(y,x),pair<LL,LL>(to_y,to_x)));
}
 
void solve(){
	vector<LL> right_edge_h;
	for(int h=0;h<H;h++){
		bool carring = false;//奇数を運んでいる状態かどうか
    	for(int w=0;w<W-1;w++){
    		if(carring){
    			if(a[h][w]%2==1) carring = false;
    			else add_move(h+1,w+1,h+1,w+2);
    		}else{
    			if(a[h][w]%2==1){
    				carring = true;
    				add_move(h+1,w+1,h+1,w+2);
    			}
    		}
    	}
    	if((carring && a[h][W-1]%2==0) || (!carring &&  a[h][W-1]%2==1)) right_edge_h.push_back(h);
    }
    if(right_edge_h.size()%2==0){
    	for(int i=0;i<right_edge_h.size();i+=2){
	    	for(int h=right_edge_h[i];h<right_edge_h[i+1];h++){
	    		add_move(h+1,W,h+2,W);
	    	}
	    }
    }else{
    	for(int i=0;i<right_edge_h.size()-1;i+=2){
	    	for(int h=right_edge_h[i];h<right_edge_h[i+1];h++){
	    		add_move(h+1,W,h+2,W);
	    	}
	    }
	    for(int h=right_edge_h[right_edge_h.size()-1];h<H-1;h++){
    		add_move(h+1,W,h+2,W);
    	}
    }
}
 
int main(){
    cin >> H >> W;
    for(int h=0;h<H;h++){
    	for(int w=0;w<W;w++){
    		cin >> a[h][w];
    	}
    }
 
    solve();
 
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
    	cout << ans[i].first.first <<" "<< ans[i].first.second;
    	cout << " ";
    	cout << ans[i].second.first <<" "<< ans[i].second.second;
    	cout << endl;
    }
    return 0;
}