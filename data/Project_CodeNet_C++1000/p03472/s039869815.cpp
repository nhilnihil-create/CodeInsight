#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, H;
    cin >> N >> H;
    int a_max = 0;
    vector<int> a(N), b(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> a.at(i);
        cin >> b.at(i);
        if ( a.at(i) > a_max )
            a_max = a.at(i);
    }

    sort(b.begin(), b.end(), greater<int>());

    int rest_hp = H;
    int ans = 0;
    for ( int i = 0; i < N; i++ ) {
        if ( b.at(i) < a_max )
            break;
        if ( rest_hp <= 0 )
            goto END;
        rest_hp -= b.at(i);
        ans++;
    }

    while ( rest_hp > 0 ) {
        rest_hp -= a_max;
        ans++;
    }

END:
    cout << ans << endl;
    return 0;
}
