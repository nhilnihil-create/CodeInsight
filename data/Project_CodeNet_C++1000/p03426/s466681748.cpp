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

LL H,W,D;
vector<pair<LL,LL>> A;//iと書かれたマスが(x,y)に位置する時、A[i]=(x,y)とする
LL Q;
vector<pair<LL,LL>> LR;
 
vector<LL> ans;

void solve(){
	//i(1<=i<=D)と書かれたマスからjと書かれたマスに移動するのに必要なコストをcost[(i,j)]とおく
	map<pair<LL,LL>,LL> cost;

	for(int start=1;start<=D && start<=H*W;start++){
		for(int end=start+D;end<=H*W;end+=D){
			//cout << start << " " << end << endl;
			LL i = A[end-D].second;
			LL j = A[end-D].first;
			LL x = A[end].second;
			LL y = A[end].first;
			cost[pair<LL,LL>(start,end)] = cost[pair<LL,LL>(start,end-D)] + abs(x-i) + abs(y-j);
		}
	}

	for(int i=0;i<Q;i++){
		LL start = LR[i].first%D;
		if(start==0) start = D;
		//cout << LR[i].first << " " << LR[i].second << " start=" << start << endl;
		ans.push_back(cost[pair<LL,LL>(start,LR[i].second)] - cost[pair<LL,LL>(start,LR[i].first)]);
	}
}

int main(){
    cin >> H >> W >> D;
    A = vector<pair<LL,LL>>(H*W+1);
    for(int h=1;h<=H;h++){
    	for(int w=1;w<=W;w++){
    		int i;cin >> i;
    		A[i] = pair<LL,LL>(h,w);
    	}
    }
	cin >> Q;
	for(int i=0;i<Q;i++){
		int L,R;cin >> L >> R;
		LR.push_back(pair<LL,LL>(L,R));
	}
 
    solve();

    for(int i=0;i<Q;i++) cout << ans[i] << endl;
    return 0;
}