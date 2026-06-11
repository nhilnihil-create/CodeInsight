#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<vector<int> > A(2,vector<int>(N,0));
    for(int i = 0; i < N; i++) {
        cin >> A.at(0).at(i);
    }
    for(int i = 0; i < N; i++) {
        cin >> A.at(1).at(i);
    }
    for(int i = 0; i < N - 1; i++) {
        A.at(0).at(i + 1) += A.at(0).at(i);
        A.at(1).at(N - 2 - i) += A.at(1).at(N - 1 - i);
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        //cout << A.at(0).at(i) + A.at(1).at(i) << endl;
        ans = max(ans,A.at(0).at(i) + A.at(1).at(i));
    }
    cout << ans << endl;

    return 0;
}