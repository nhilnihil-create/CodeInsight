#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

struct segmentTree
{
    struct node
    {
        int val;
        void setLeaf(int idx) { val = 0; }
        friend node operator+(const node &lhs, const node &rhs)
        {
            node res;
            res.val = max(lhs.val, rhs.val);
            return res;
        }
        void applyUpdate(int upd) { val = upd; }
        int query() { return val; }
    };

    int N;
    vector<node> st;
    segmentTree(int n) : N(n), st(4*N+5) {}

    void buildHelper(int u, int l, int r)
    {
        if(l == r)
        {
            st[u].setLeaf(l);
            return;
        }
        int m = (l+r)/2;
        buildHelper(2*u, l, m);
        buildHelper(2*u+1, m+1, r);
        st[u] = st[2*u] + st[2*u+1];
    }
    void build() { buildHelper(1, 1, N); }

    node queryHelper(int u, int l, int r, int i, int j)
    {
        if(l >= i && r <= j)
            return st[u];
        int m = (l+r)/2;
        if(j <= m)
            return queryHelper(2*u, l, m, i, j);
        else if(i >= m+1)
            return queryHelper(2*u+1, m+1, r, i, j);
        else
            return queryHelper(2*u, l, m, i, j) + queryHelper(2*u+1, m+1, r, i, j);
    }
    int query(int i, int j) { return queryHelper(1, 1, N, i, j).query(); }

    void updateHelper(int u, int l, int r, int pos, int upd)
    {
        if(l == r)
        {
            st[u].applyUpdate(upd);
            return;
        }
        int m = (l+r)/2;
        if(pos <= m)
            updateHelper(2*u, l, m, pos, upd);
        else
            updateHelper(2*u+1, m+1, r, pos, upd);
        st[u] = st[2*u] + st[2*u+1];
    }
    void update(int pos, int upd) { updateHelper(1, 1, N, pos, upd); }
};

segmentTree st(200005);
int h[200005], a[200005];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        int bmax = a[i];
        if(h[i] > 1)
            bmax += st.query(1, h[i]-1);
        st.update(h[i], bmax);
    }
    cout << st.query(1, n) << endl;
}