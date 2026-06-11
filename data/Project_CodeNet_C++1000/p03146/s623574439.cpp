#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// グローバル変数
ll s;
vector<ll> c;

// 関数プロトタイプ
void input();
void solve();
int dfs(ll, int);

int main(void)
{
    input();
    solve();  
}

// 標準入力
void input() {
    cin >> s;
}

void solve() {
    c.push_back(s);
    cout << dfs(s, 1) << endl;
}

int dfs(ll a, int i) {
    ll res = 0;
    i++;
    if(a%2 == 0) {
        res = a / 2;
    } else {
        res = 3 * a + 1;
    }
    if(find(c.begin(), c.end(), res) != c.end()) {
        return i;
    } else {
        c.push_back(res);
        return dfs(res, i);
    }
}