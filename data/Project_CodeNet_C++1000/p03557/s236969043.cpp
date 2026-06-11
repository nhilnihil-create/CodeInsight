#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);

    rep(i, N) cin >> A.at(i);
    rep(i, N) cin >> B.at(i);
    rep(i, N) cin >> C.at(i);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    long long sum{0};
    rep(i, N){
        auto num_a = distance(A.begin(), lower_bound(A.begin(), A.end(), B.at(i)));
        auto num_c = N - distance(C.begin(), upper_bound(C.begin(), C.end(), B.at(i)));
        sum += num_a * num_c;
    }

    cout << sum << endl;
}
