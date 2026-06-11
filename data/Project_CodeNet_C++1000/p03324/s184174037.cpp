#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int D;
    cin >> D;
    ll min_num =1;
    if(D == 0){
        min_num = 1;
    }
    else{
        for(int i=0;i<D;i++){
            min_num = min_num*100;
        }
    }
    ll N;
    cin >> N;
    ll ans;
    if(N!=100){
        ans = min_num * N;
    }
    else{
        ans = min_num * 101;
    }
    cout << ans << endl;
}