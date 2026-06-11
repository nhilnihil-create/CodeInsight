#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> neg, pos;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) k--;
        else if (a < 0) neg.push_back(a);
        else if (a > 0) pos.push_back(a);
    }

    if(n == 1 && k == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1e17;


    sort(neg.rbegin(),neg.rend());


    for (int i = max(0 ,k - (int)pos.size() - 1); i < min(k, (int) neg.size()); i++) {
        ll dist = neg[i] * (-1);
        if(i != k - 1) {
            dist *= 2;
            ll cnt = k - i - 1;
            dist += (pos[cnt - 1]);
        }


        ans = min(ans, dist);
    }

    for (int i = max(0, k - (int)neg.size() - 1); i < min(k, (int) pos.size()); i++) {
        ll dist = pos[i];
        if(i != k - 1) {
            dist *= 2;
            ll cnt = k - i - 1;
            dist += (neg[cnt - 1] * (-1));
        }

        ans = min(ans, dist);
    }
    cout << ans << '\n';
}