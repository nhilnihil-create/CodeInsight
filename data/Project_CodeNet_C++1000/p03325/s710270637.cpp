#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    vector<int> a(N);
    for ( int i=0; i<N; i++ )
        cin >> a.at(i);

    int a_;
    long long ans = 0;
    for ( int i=0; i<N; i++ ) {
        a_ = a.at(i);
        while ( a_ % 2 == 0 ) {
            a_ /= 2;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
