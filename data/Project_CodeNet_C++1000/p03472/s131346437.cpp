#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N, H;
    ll count = 0;
    vector<ll> A, B;
    cin >> N >> H;
    A.resize(N);
    B.resize(N);
    for(ll i = 0;i < N;i++) cin >> A[i] >> B[i];
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());
    for(auto &i: B) {
        if(i <= A.front()) break;
        H -= i;
        count++;
        if(H <= 0) {
            cout << count << endl;
            return 0;
        }
    }
    count += ceil((double)H / A.front());
    cout << count << endl;
    return 0;
}
