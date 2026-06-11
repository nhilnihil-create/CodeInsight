#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    vector<int> A(N);
    for ( int i = 0; i < N; i++ )
        cin >> A.at(i);

    int ans = 0;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = i+1; j < N; j++ ) {
            ans = max(abs(A.at(i) - A.at(j)), ans);
        }
    }

    cout << ans << endl;
    return 0;
}

