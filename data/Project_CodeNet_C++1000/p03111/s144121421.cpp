#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
const ll mod = 1e9 + 7;
const ll inf = 1e12;
const double pi = 3.141592;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int dfs(int i, int a, int b, int c, const vector<int>& l, int A, int B, int C){
    if(i == l.size()){
        if(!a || !b || !c)
            return 100000;
        else
            return abs(a - A) + abs(b - B) + abs(c - C);
    }

    int res1 = dfs(i + 1, a, b, c, l, A, B, C);
    int res2 = dfs(i + 1, a + l[i], b, c, l, A, B, C) + (a ? 10 : 0);
    int res3 = dfs(i + 1, a, b + l[i], c, l, A, B, C) + (b ? 10 : 0);
    int res4 = dfs(i + 1, a, b, c + l[i], l, A, B, C) + (c ? 10 : 0);
    return min({res1, res2, res3, res4});
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    cout << dfs(0, 0, 0, 0, l, a, b, c) << "\n";
    return 0;
}