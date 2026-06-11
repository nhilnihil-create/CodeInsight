#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = (int)(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = (int)(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const long long MOD = 1000000007LL;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int n, m;
vector< vector<int> > g;
vector<int> col;

void dfs(int v, int c){
    col[v] = c;

    for(auto e : g[v]){
        if(col[e] == -1){
            dfs(e, c ^ 1);
        }
    }

    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    g.resize(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g[--a].emplace_back(--b);
        g[b].emplace_back(a);
    }

    col.resize(n, -1);
    dfs(0, 0);

    bool flag = true;
    rep(i, n){
        for(auto e : g[i]){
            flag &= col[i] != col[e];
        }
    }

    if(flag){
        vector<int> cnt(2);
        rep(i, n){
            ++cnt[col[i]];
        }
        cout << (lint)cnt[0] * cnt[1] - m << endl;
    }else{
        cout << (lint)n * (n - 1LL) / 2LL - m << endl;
    }

    return 0;
}