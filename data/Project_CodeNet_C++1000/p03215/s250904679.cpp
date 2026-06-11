#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const int BITS_LEN = 62;

vector<ll> a;
vector<ll> sums;

void calc_sums(const ll N) {
    vector<ll> part_sums(N + 1, 0);
    for (int i = 0; i < N; i++) {
        part_sums[i + 1] = part_sums[i] + a[i];
    }

    int ind = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sums[ind] = part_sums[j + 1] - part_sums[i];
            ind++;
        }
    }
}

int main(void) {
    ll N, K;
    cin >> N >> K;

    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll sums_len = N * (N + 1) / 2;
    sums.resize(sums_len);
    calc_sums(N);

    // for (int i = 0; i < sums_len; i++) {
    //     cout << sums[i] << endl;
    // }
    // // sort by descending order
    // sort(sums.begin(), sums.end(), [](const ll &a, const ll &b) {
    //         return a > b;
    //         });

    ll cur = 0;
    for (int i = 40; i >= 0; i--) {
        ll ncur = cur + (1LL << i);
        int ok = 0;
        for (int j = 0; j < sums_len; j++) {
            if ((ncur & sums[j]) == ncur) ok++;
        }
        if (ok >= K) cur = ncur;
    }

    cout << cur << endl;

    return 0;
}
