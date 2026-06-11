#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N),B(N),plus(N);
    ll sum = 0;
    for (int i=0;i<N;i++) {
        cin >> A[i] >> B[i];
        plus[i] = A[i]+B[i];
        sum -= B[i];
    }
    sort(plus.rbegin(),plus.rend());
    for (int i=0;i<N;i+=2){
        sum += plus[i];
    }
    cout << sum << "\n";
}