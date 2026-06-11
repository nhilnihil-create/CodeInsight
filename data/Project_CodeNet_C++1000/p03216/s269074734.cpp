#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
//参考: http://kmjp.hatenablog.jp/entry/2018/11/26/0900
ll m[1234567];
ll c[1234567];
ll mc[1234567];
int main(){
    int n;
    string s;
    int q;
    cin >> n >> s >> q;
    rep(i,n){
        if(s[i] == 'M')m[i]++;
        if(s[i] == 'C')c[i]++;
    }
    rep(i,n){
        m[i+1] += m[i];
        c[i+1] += c[i];
    }
    rep(i,n){
        if(s[i] == 'C'){
            mc[i] = m[i];
        }
    }
    rep(i,n){
        mc[i+1] += mc[i];
    }
    while(q--){
        int k;
        cin >> k;
        k--;
        ll ans = 0;
        rep(i,n){
            if(s[i] == 'D'){
                int pos = min(n,i+k);
                ans += mc[pos]-mc[i] - m[i]*(c[pos]-c[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}