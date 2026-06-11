#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0, K;
    cin >> N >> K;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    int ans = 1000000010;
    for(int i = 0; i < N - K + 1; i++) {
        ans = min(ans, A.at(i) - A.at(i + K - 1));
        //cout << A.at(i) << ':' << A.at(i + K - 1) << endl;
    }
    cout << ans << endl;

    return 0;
}