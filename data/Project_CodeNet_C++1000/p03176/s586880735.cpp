#include<bits/stdc++.h>
#define N 2000009
#define ll long long
#define ld long double
#define ff first
#define ss second
#define inf 1000000005
#define mod 1000000007
using namespace std;
ll t[1000001];
/*void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}*/
int n, h[200009], b[200009];
void update(int v, int tl, int tr, int pos, ll new_val) {
    if(tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

ll get(int v, int tl, int tr, int l, int r) {
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return max(get(v * 2, tl, tm, l, min(r, tm)),
               get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}
set<pair<int, int> > s;
ll ans;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>h[i];
        s.insert({h[i], i});
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(set<pair<int, int> >:: iterator it = s.begin(); it != s.end();it++) {
        int ind = it->second;
        ll prevma = get(1, 1, n, 1, ind - 1);
        ll cur = prevma + b[ind];
        ans = max(ans, cur);
        update(1, 1, n, ind, cur);
    }
    cout<<ans;
}
