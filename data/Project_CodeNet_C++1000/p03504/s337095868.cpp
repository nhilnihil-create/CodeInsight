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
priority_queue<tuple<LL,LL,LL>> prog;
 
LL ans = 0;
 
void solve(){
    vector<LL> finish_time(C+1,0);//チャンネルiの終了予定時刻をfinish_time[i]とする
    for(int time=1;time<=100000;time++){
        while(!prog.empty()){
            tuple<LL,LL,LL> p = prog.top();
            LL start = -get<0>(p);
            LL end = get<1>(p);
            LL channel = get<2>(p);
            if(start!=time) break;
            finish_time[channel] = end;
            prog.pop();
        }
        //時刻timeの時点で録画中のレコーダーの数
        LL counter = 0;
        for(int c=1;c<=C;c++){
            if(finish_time[c]>=time) counter++;
        }
        ans = max(ans,counter);
    }
}
 
int main(){
    cin >> N >> C;
    for(int i=0;i<N;i++){
        LL s,t,c;cin >> s >> t >> c;
        prog.push(tuple<LL,LL,LL>(-s,t,c));
    }
 
    solve();
 
    cout << ans << endl;
    return 0;
}