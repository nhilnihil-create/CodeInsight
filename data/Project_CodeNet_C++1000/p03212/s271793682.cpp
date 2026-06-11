#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
int P(int i) {
    int ten = 1;
    rep(d, i) {
        ten *= 10;
    }
    return ten;
}

int ans = 0;
ll n;
void dfs(int keta, ll nm, int use) {

    for (int i = 3; i <= 7; i += 2) {
        ll number = nm + (double)i * P(keta);
        int U=use;
        if (number > n)
            continue;
        if (i == 3)
            U = U | 0b001;
        else if (i == 5)
            U = U | 0b010;
        else if (i == 7)
            U = U | 0b100;
        //cout << "nm==" << number << " use==" << U << endl;
        if (U == 0b111) {
            ans++;
        }
        dfs(keta + 1, number, U);
    }
}

int main() {
    cin >> n;

    dfs(0, 0, 0);
    cout << ans << endl;

    return 0;
}
