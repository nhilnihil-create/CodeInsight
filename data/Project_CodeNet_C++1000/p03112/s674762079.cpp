#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll func(vector<ll> &v, ll x) {
    vector<ll>::iterator ite;
    ll ans = 0;
    ite = lower_bound(v.begin(), v.end(), x);

    //寺の場所が全て神社の場所未満の時
    if (ite == v.end()) {
        ll z = *(ite-1);
        ans += x-z;
    }
    //寺の場所が全て神社の場所以上の時
    else if (ite == v.begin()) {
        ll z = *ite;
        ans += z-x;
    }
    //それ以外
    else {
        ll z = *ite, w = *(ite-1);
        ans += min(z-x, x-w);
    }
    return ans;
}

int main() {
    int A, B, Q;   cin >> A >> B >> Q;
    vector<ll> temple(B), shrine(A), ans(Q);
    for (int i = 0; i < A; i++)
        cin >> shrine[i];
    for (int i = 0; i < B; i++)
        cin >> temple[i];

    sort(shrine.begin(), shrine.end());
    sort(temple.begin(), temple.end());

    for (int i = 0; i < Q; i++) {
        ll x;   cin >> x;
        //shrine から
        vector<ll>::iterator ite = lower_bound(shrine.begin(), shrine.end(), x);    //x以上の神社の場所
        //神社の場所が全てx未満の時
        if (ite == shrine.end()) {
            ite--;
            ll y = *ite;
            ans[i] = x-y;
            ans[i] += func(temple, y);
        }
        //神社の場所が全てx以上の時
        else if (ite == shrine.begin()) {
            ll y = *ite;
            ans[i] = y-x;
            ans[i] += func(temple, y);
        }
        //それ以外
        else {
            ll y = *ite;
            ite--;
            ll z = *ite;
            ans[i] = min(y-x + func(temple, y), x-z + func(temple, z));
        }
        
        ite = lower_bound(temple.begin(), temple.end(), x);
        if (ite == temple.end()) {
            ite--;
            ll y = *ite;
            ans[i] = min(x-y + func(shrine, y), ans[i]);
        }
        else if (ite == temple.begin()) {
            ll y = *ite;
            ans[i] = min(y-x + func(shrine, y), ans[i]);
        }
        else {
            ll y = *ite;
            ite--;
            ll z = *ite;
            ans[i] = min(ans[i], min(y-x + func(shrine, y), x-z + func(shrine, z)));
        }
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << endl;
    return 0;
}