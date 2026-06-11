#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <vector<int>> A(2, vector<int>(N, 0));
    for (int i=0; i<2; i++) {
        for (int j=0; j<N; j++) cin >> A.at(i).at(j);
    }
    long long ans=0;
    for (int i=0; i<N; i++) {
        long long tmp=0;
        for (int j=0; j<=i; j++) tmp+=A.at(0).at(j);
        for (int j=i; j<N; j++) tmp+=A.at(1).at(j);
        ans = max(tmp, ans);
    }
    cout << ans << endl;;
}