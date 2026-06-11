#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
int h[200100], a[200100];

struct segtree {
    int size;
    vector<int> node;
    
    segtree(int n) {
        size = 1;
        while (size<n) size *= 2;
        node.resize(2*size-1);
        fill(node.begin(), node.end(), 0);
    }

    void update(int k, int a) {
        k += size-1;
        node[k] = a;
        while (k>0) {
            k = (k-1)/2;
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }
    
    int query(int a, int b, int k, int l, int r) {
        if (r<=a || b<=l) return 0;
        if (a<=l && r<=b) return node[k];
        else {
            int vl = query(a, b, 2*k+1, l, (l+r)/2);
            int vr = query(a, b, 2*k+2, (l+r)/2, r);
            return max(vl, vr);
        }
    }
    
    int get(int a, int b) {
        return query(a, b, 0, 0, size);
    }
};
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> h[i];
    rep(i, N) cin >> a[i];
    segtree st(200100);
    rep(i, N) st.update(h[i], st.get(0, h[i])+a[i]);
    cout << st.get(0, 200100) << endl;
}