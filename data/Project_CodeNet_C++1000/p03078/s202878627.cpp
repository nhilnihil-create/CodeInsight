#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

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

vector<ll> A;
vector<ll> B;
vector<ll> C;

vector<ll> ans;

bool cond(const ll border, const ll K) {
    ll cnt = 0;
    for (int i = 0; i < (int) A.size(); i++) {
        for (int j = 0; j < (int) B.size(); j++) {
            for (int k = 0; k < (int) C.size(); k++) {
                ll sum = A[i] + B[j] + C[k];
                if (sum < border) {
                    break;
                }
                cnt++;
                if (cnt >= K) {
                    return true;
                }
            }
        }
    }
    return false;
}

ll calc_border(const ll K) {
    ll left = -1, right = LONG_LONG_MAX / 2, mid;
    while (right - left > 1) {
        mid = ((right - left) / 2) + left;
        // printf("left: %lld, right: %lld, mid: %lld\n", left, right, mid);
        if (cond(mid, K)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

void collect_cakes(const ll border, const ll K) {
    ll cnt = 0;
    for (int i = 0; i < (int) A.size(); i++) {
        for (int j = 0; j < (int) B.size(); j++) {
            for (int k = 0; k < (int) C.size(); k++) {
                ll sum = A[i] + B[j] + C[k];
                if (sum <= border) {
                    break;
                }
                ans.push_back(sum);
                cnt++;
                if (cnt >= K) {
                    return;
                }
            }
        }
    }

    while (cnt < K) {
        ans.push_back(border);
        cnt++;
    }
}

int main(void) {
    int X, Y, Z;
    ll K;
    cin >> X >> Y >> Z >> K;

    A.resize(X);
    for (int i = 0; i < X; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    B.resize(Y);
    for (int i = 0; i < Y; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    C.resize(Z);
    for (int i = 0; i < Z; i++) {
        cin >> C[i];
    }
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());

    ll border = calc_border(K);
    // cout << border << endl;

    collect_cakes(border, K);
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
