#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) cin >> A.at(i).at(j);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll tmp = 0;
        for (int j = 0; j < N; j++) {
            if (j < i) tmp += A.at(0).at(j);
            else if (j == i) tmp += A.at(0).at(j) + A.at(1).at(j);
            else tmp += A.at(1).at(j);
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
