#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }


int main(void) {
    llint n, k;
    cin >> n >> k;

    if(k%2==1) {
        llint kbai, ans;
        kbai = n/k;
        ans = kbai*kbai*kbai;
        cout << ans << endl;
    }
    else {
        llint kbai, ans, kmod;
        kbai = n/k;
        ans = kbai*kbai*kbai;

        kmod=0;
        for(llint in=1;in<=n;in++) {
            if(in%k==(k/2)) kmod++;
        }
        ans += kmod*kmod*kmod;
        cout << ans << endl;
    }

    
    return 0;
}
