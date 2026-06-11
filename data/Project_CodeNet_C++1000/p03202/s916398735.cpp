#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll N;
vector<ll> A;

bool isOK(ll x) {
    if (x == 1) {
        for (ll i = 1; i < N; i++) {
            if (A[i - 1] >= A[i]) {
                return false;
            }
        }
        return true;
    }

    //入ってないところは0ということを示す
    map<ll, ll> mp;

    for (ll i = 1; i < N; i++) {
        if (A[i - 1] < A[i]) {
            //0を入れていくだけなので何もしない
            continue;
        }

        //先を全部消す
        mp.erase(mp.upper_bound(A[i - 1]), mp.end());

        //x - 1でない位置を見つける
        ll j = A[i];
        while (mp[j] == x - 1 && j > 0) {
            mp.erase(j--);
        }

        if (j == 0) {
            //全部ダメ
            return false;
        }

        //ここの桁の値を1上げる
        mp[j]++;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll ng = 0, ok = N;
    while (ng + 1 != ok) {
        ll mid = (ng + ok) / 2;
        (isOK(mid) ? ok = mid : ng = mid);
    }
    cout << ok << endl;
}