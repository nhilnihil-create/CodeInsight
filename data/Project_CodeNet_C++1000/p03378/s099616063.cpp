#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// グローバル変数
ll n, m, x;
vector<ll> a;

// 関数プロトタイプ
void input();
void solve();

int main(void)
{
    input();
    solve();  
}

// 標準入力
void input() {
    cin >> n >> m >> x;
    a.resize(m);
    for (int i = 0; i < m;i++) {
        cin >> a[i];
    }
}

void solve() {
    int bef = 0;
    int aft = 0;
    for (int i = 0; i < m;i++) {
        if(a[i]<x) {
            bef++;
        }
        if(a[i]>x) {
            aft++;
        }
    }
    cout << min(bef, aft) << endl;
}