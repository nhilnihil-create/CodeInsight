#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt[3] = {};
    string S;

    cin >> S;
    for ( int i = 0; i < S.size(); i++ ) {
        cnt[S[i] - 'a']++;
    }
    sort(cnt, cnt + 3);
    if ( cnt[2] - cnt[0] <= 1 ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return ( 0 );
}
