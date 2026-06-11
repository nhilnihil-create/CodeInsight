#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    rep(i, N){
        cin >> A[i];
    }
    rep(i, N){
        cin >> B[i];
    }
    rep(i, N){
        cin >> C[i];
    }

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    ll sum = 0;
    rep(i, N){
        auto itr_a = lower_bound(A.begin(), A.end(), B[i]);
        ll a_num = itr_a - A.begin();
        auto itr_c = upper_bound(C.begin(), C.end(), B[i]);
        ll c_num = C.end() - itr_c;
        sum += a_num * c_num;

    }

    cout << sum << endl;


    return 0;
}
