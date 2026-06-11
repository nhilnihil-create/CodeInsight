#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<int> v, w;

    ll b = 0, a = 0, d = 0;
    ll c = 0;
    rep(i, n) {
        for (int j = 0; j < s[i].size() - 1; j++) {
            if (s[i][j] == 'A' && s[i][j + 1] == 'B') {
                c++;
            }
        }

        if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') {
            d++;
        } else if (s[i][0] == 'B') {
            b++;
        } else if (s[i][s[i].size() - 1] == 'A') {
            a++;
        }
    }

    if(d==0){
        c += min(a, b);
    }else{
        if((a+b)==0){
            c += d - 1;
        }else{
            c += d + min(a, b);
        }
    }

    cout << c << endl;
}