#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    for (int i=0; i<2; i++){
        for (int j=0; j<N; j++){
            cin >> A.at(i).at(j);
        }
    }

    int ans = 0, buf = 0;
    for (int i=0; i<N; i++){
        buf = 0;
        for (int j=0; j<=i; j++) buf += A.at(0).at(j);
        for (int j=i; j<N; j++) buf += A.at(1).at(j);
        ans = max(buf, ans);
    }

    cout << ans << endl;
    return 0;
}