#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for ( int i = 0; i < N; i++ ) cin >> A.at(i);
    for ( int i = 0; i < N; i++ ) cin >> B.at(i);
    for ( int i = 0; i < N; i++ ) cin >> C.at(i);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int i;
    int ci = 0;
    vector<long long> v(N);   /* 各中部パーツの上に載せられる上部パーツの数 */
    for ( int bi = 0; bi < N; bi++ ) {
        int b = B.at(bi);
        for ( i = ci; i < N && C.at(i) <= b; i++ ) {}
        if ( i == N ) i--;
        if ( C.at(i) <= b ) break;
        v.at(bi) = N - i;
        ci = i;
    }

    /* v を後ろからの累積和にする */
    for ( i = N-1; i >= 0; i-- ) {
        if ( i != N-1 ) v.at(i) += v.at(i+1);
    }

    long long ans = 0;
    int bi = 0;
    for ( int ai = 0; ai < N; ai++ ) {
        int a = A.at(ai);
        for ( i = bi; i < N && B.at(i) <= a; i++ ) {}
        if ( i == N ) i--;
        if ( B.at(i) <= a ) break;
        ans += v.at(i);
        bi = i;
    }

    cout << ans << endl;
    return 0;
}

