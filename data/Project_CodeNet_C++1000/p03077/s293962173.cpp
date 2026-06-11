#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    LL N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;
    
    if(N <= min({A, B, C, D, E})){
        cout << 5 << endl;
        return 0;
    }

    LL r1 = min({N, A});
    LL r2 = min({r1, B});
    LL r3 = min({r2, C});
    LL r4 = min({r3, D});
    LL r5 = min({r4, E});

    LL ans = (N%r5 == 0)? N/r5 + 5 - 1 : N/r5 + 5;
    cout << ans << endl;
    return 0;
}