//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/arc098/tasks/arc098_c

//ポイント：
//Yを決めうちした上でループを回す
 
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
#include <stack>
#include <map> 
#include <unordered_map> 
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

LL N,K,Q;
LL A[2000];

LL ans = INF;

void solve(){
    //A[i]=Yと決め打ちする
    for(int i=0;i<N;i++){
        LL Y = A[i];
        typedef priority_queue<LL,vector<LL>,greater<LL>> pri_queue;
        vector<pri_queue> part;
        part.push_back(pri_queue());
        for(int j=0;j<N;j++){
            if(A[j]<Y){
                part.push_back(pri_queue());
                continue;
            }
            part[part.size()-1].push(A[j]);
        }

        vector<LL> cand;
        for(int j=0;j<part.size();j++){
            while(part[j].size()>=K){
                cand.push_back(part[j].top());
                part[j].pop();
            }
        }
        sort(cand.begin(),cand.end());
        if(cand.size()<Q) continue;
        LL X = cand[Q-1];
        ans = min(ans,X-Y);
    }
}
 
int main(){
	cin >> N >> K >> Q;
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();

	cout << ans << endl;
    return 0;
}