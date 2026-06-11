#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

class InversionCount {
public:
    InversionCount(vector<ll> target) : target_(target) {}
    ll count(ll left = 0, ll right = -1) {
        if (right < 0) {
            //rはtarget_.size()で初期化
            right = target_.size();
        }
        if (right <= left + 1) {
            return 0;
        }
        ll mid = (left + right) / 2;
        ll result = 0;
        //左半分を数える
        result += count(left, mid);

        //右半分を数える
        result += count(mid, right);

        //左右またぐ数を数える
        result += merge(left, mid, right);

        return result;
    }
private:
    ll merge(ll left, ll mid, ll right) {
        vector<ll> l, r;
        for (ll i = left; i < mid; i++) {
            l.push_back(target_[i]);
        }
        for (ll i = mid; i < right; i++) {
            r.push_back(target_[i]);
        }
        //番兵
        l.push_back(LLONG_MAX);
        r.push_back(LLONG_MAX);

        ll left_index = 0;
        ll right_index = 0;
        ll result = 0;
        for (ll i = left; i < right; i++) {
            if (l[left_index] <= r[right_index]) {
                target_[i] = l[left_index];
                left_index++;
            } else {
                target_[i] = r[right_index];
                right_index++;
                result += ((mid - left) - left_index);
            }
        }
        return result;
    }

    vector<ll> target_;
};

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }

    auto medianNum = [&](ll x) {
        vector<ll> b(N + 1, 0);
        for (ll i = 0; i < N; i++) {
            b[i + 1] = (a[i] >= x ? 1 : -1) + b[i];
        }
        InversionCount ic(b);
        return N * (N + 1) / 2 - ic.count();
    };

    ll ok = 0, ng = INT_MAX;
    while (ok + 1 != ng) {
        ll mid = (ok + ng) / 2;
        ll num = medianNum(mid);
        (2 * num >= N * (N + 1) / 2 ? ok = mid : ng = mid);
    }
    cout << ok << endl;
}