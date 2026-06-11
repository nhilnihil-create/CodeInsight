#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

struct segtree{
    int size;
    vector<ll> dat;
    ll init = 0;

    segtree (int N) {
        size = 1;
        while (size < N) size *= 2;
        dat = vector<ll>(2*size-1, init);
    }

    ll op(ll a, ll b) {
        return max(a, b);
    }

    void update(int i, ll x) { 
        i += size-1;
        dat[i] = x;
        while (i > 0) {
            i = (i-1)/2;
            dat[i] = op(dat[2*i+1], dat[2*i+2]);
        }
        return;
    }

    ll get(int i) {
        return dat[i+size-1];
    }

    ll query(int a, int b) {
        return query(a, b, 0, 0, size);
    }
    

    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init;
        if (a <= l && r <= b) return dat[k];
        ll lv, rv;
        lv = query(a, b, 2*k+1, l, (l+r)/2);
        rv = query(a, b, 2*k+2, (l+r)/2, r);
        return op(lv, rv);
    }
};

int main() {
    int N;
    cin >> N;
    vector<ll> H(N), A(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < N; i++) cin >> A[i];
    
    segtree sgt(N+1);
    for (int i = 0; i < N; i++) {
        sgt.update(H[i], sgt.query(0, H[i])+A[i]);
    }
    cout << sgt.query(0, N+1) << endl;
    return 0;
}