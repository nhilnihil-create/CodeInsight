#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n;
    //現在持っている問題の難易度
    map<int, int> mp_d;
    rep(i,n) {
        int D;
        cin >> D;
        mp_d[D]++;
    }
    cin >> m;
    //必要な問題の難易度
    vector<int> T(m);
    map<int, int> mp_t;
    rep(i,m) {
        cin >> T[i];
        mp_t[T[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (mp_t[T[i]] > mp_d[T[i]]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}
