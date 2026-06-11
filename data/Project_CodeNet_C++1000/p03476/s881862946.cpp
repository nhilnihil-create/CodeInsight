#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int Q;
    cin >> Q;
    vec<int> f(1e5 + 7, 0);
    vec<int> s(1e5 + 7, 0);
    f[0] = 0;
    f[1] = 0;
    for (int i = 2; i <= 1e5 + 3; ++i) {
        if (f[i] == 0) {
            f[i] = i;
            s[i] = 1;
        }
        for (int j = i + i; j <= 1e5 + 3; j += i)
            f[j] = i;
    }
    for(int i=1e5+3;i>=3;i-=2){
        if(s[i] == 1 && s[(i+1)/2] == 1){
            s[i] = 1;
        } else {
            s[i] = 0;
        }
    }
    s[2] = 0;
    for(int i=3;i<=1e5+3;++i) s[i+1]+=s[i];

    rep(_, Q) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
}
