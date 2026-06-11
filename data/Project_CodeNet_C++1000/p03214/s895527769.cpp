#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    double ave = 0;
    vector<double> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ave += A[i];
    }
    ave /= (double)N;
    vector<pair<double, int>> ans;
    for (int i = 0; i < N; i++) {
        ans.emplace_back(abs(A[i] - ave), i);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].second << endl;
    return 0;
}