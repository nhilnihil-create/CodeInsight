#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;

    vector<int> ps {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    vector<int> div(15);
    rep(i, N) {
        int temp = i + 1;
        rep(j, 15) {
            while (temp % ps[j] == 0) {
                temp /= ps[j];
                div[j]++;
            }
        }
    }

    ll ans = 0;
    rep(i, 15) {
        if (div[i] < 2) continue;
        rep(j, 15) {
            if (div[j] < 4 || i == j) continue;
            for (int k = j + 1; k < 15; ++k) {
                if (div[k] < 4 || i == k) continue;
                ans++;
            }
        }
    }
    rep(i, 15) {
        if (div[i] < 14) continue;
        rep(j, 15) {
            if (div[j] < 4 || i == j) continue;
            ans++;
        }
    }
    rep(i, 15) {
        if (div[i] < 24) continue;
        rep(j, 15) {
            if (div[j] < 2 || i == j) continue;
            ans++;
        }
    }
    rep(i, 15) {
        if (div[i] > 73) ans++;
    }
    cout<<ans<<endl;
}