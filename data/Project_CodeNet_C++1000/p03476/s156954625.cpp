#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool flag[100001];//その数を見たかどうか/falseなら素数


int main() {
    int Q;
    cin >> Q;
    vector<int> l(Q), r(Q);
    rep(i,Q) cin >> l[i] >> r[i];
    
    vector<int> prime_v(100000);

    for (int i = 2; i <= 100000; ++i) {
        if(!flag[i]) {
            for (int j = i * 2; j <= 100000; j += i) flag[j] = true;
        }
    }
    for (int i = 3; i <= 100000; i += 2) if (!flag[i] && !flag[(i+1)/2]) ++prime_v[i];//今回は2が含まれない
    for (int i = 3; i <= 100000; i += 2) prime_v[i] += prime_v[i-2];

    rep(i,Q) {
        if (l[i] == 1) cout << prime_v[r[i]] << endl;
        else cout << prime_v[r[i]] - prime_v[l[i]-2] << endl;
    }
}

