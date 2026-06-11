#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> A(N);
    set<ll> st;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        st.insert(A[i]);
    }

    auto isOK = [&](ll a) {
        //最小値をYとして決め打つ
        for (ll Y : st) {
            //Aの各要素を
            //  1)Y未満
            //  2)Y以上かつY + a以下
            //  3)Y + a超過
            //のどれかという情報へ変換する
            vector<ll> B;
            B.push_back(1);
            for (ll i = 0; i < N; i++) {
                B.push_back(
                    (A[i] < Y ? 1: (A[i] > Y + a ? 3 : 2))
                );
            }
            B.push_back(1);

            ll num_b = 0, num_2 = 0, cnt = 0;
            for (ll i : B) {
                if (i == 1) {
                    ll n = max(num_b - K + 1, (ll)0);
                    cnt += min(n, num_2);
                    num_b = num_2 = 0;
                } else if (i == 2) {
                    num_b++;
                    num_2++;
                } else {
                    num_b++;
                }
            }
            if (cnt >= Q) {
                return true;
            }
        }
        return false;
    };

    ll ng = -1, ok = INT_MAX;
    while (ng + 1 != ok) {
        ll mid = (ng + ok) / 2;
        (isOK(mid) ? ok = mid : ng = mid);
    }

    cout << ok << endl;
}