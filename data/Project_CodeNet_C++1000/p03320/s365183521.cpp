#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()


int get_dig_sum(ll x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

bool is_x_less_than_y(ll x, ll y) {
    return x * get_dig_sum(y) < y * get_dig_sum(x);
}

ll get_num(vector<int> v) {
    ll y = 0;
    reverse(all(v));
    for (int x : v)
        y = y * 10 + x;
    return y;
}

ll f(ll x) {
    vector<int> v;

    while (x > 0) {
        v.push_back(x % 10);
        x /= 10;
    }

    ll ans = -1;

    for (int i = 0; i < v.size(); i++) {
        for (int j = v[i]; j < 10; j++) {
            v[i] = j;

            ll cur = get_num(v);

            if (ans == -1 || is_x_less_than_y(cur, ans)) {
                ans = cur;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    ll x = 1;
    while (k--) {
        cout << x << "\n";
        x = f(x + 1);
    }

    return 0;   
}