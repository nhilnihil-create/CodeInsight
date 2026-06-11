#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

using ll = long long;

int main() {

    ll n, k;

    cin >> n >> k;

    vector<ll> plusNum;
    vector<ll> minusNum;

    for(ll i = 0; i < n; ++i) {
        ll num;
        cin >> num;

        if(num > 0)
            plusNum.push_back(num);
        else
            minusNum.push_back(-num);

    }

    reverse(minusNum.begin(), minusNum.end());

    ll ans = LLONG_MAX;

    for(ll i = 0; i <= k; ++i) {

        if(i > plusNum.size() || k - i > minusNum.size())
            continue;

        ll p = 0;
        if(i > 0)
            p = plusNum[i - 1];

        ll m = 0;
        if(k - i > 0)
            m = minusNum[k - i - 1];

        if(p < m)
            swap(p, m);
        
        ans = min(ans, p + 2*m);

    }


    cout << ans << endl;

    return 0;

}