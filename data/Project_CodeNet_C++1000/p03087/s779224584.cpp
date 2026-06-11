#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)

ll pow(ll a, ll n) { //compute a^n with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll pow(ll a, ll n, ll mod) { //compute a^n (mod mod) with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int N,Q;
    cin >> N >> Q; // 配列サイズ
    string S;
    cin >> S;
    vector<int> a(N, 0);
    char pre,now;
    rep0(i, N-1){
        now = S[i];
        if(i != 0){
            if(now == 'C' & pre == 'A') a[i] = 1;
        }
        pre = now;
    }

    // 累積和
    vector<int> s(N+1, 0); // s[0] = 0 になる
    rep0(i, N-1) s[i+1] = s[i] + a[i];
    rep1(i,Q){
        ll l,r;
        cin >> l >> r;
        cout << s[r] - s[l] << endl;
    }

    return 0;
}