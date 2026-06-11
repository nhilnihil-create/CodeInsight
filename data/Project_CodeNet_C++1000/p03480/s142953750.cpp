#include <bits/stdc++.h>
using namespace std;


int main()
{
    string S;
    cin >> S;

    int N = S.size();
    int ans = INT_MAX;
    /* K をある値に決めたとき、K < i < N-K を満たす S[i] は自由に変えられる。
       なぜなら、例えば i = K+1 のとき、S[0:K+1] をフリップし、S[0:K] をフリップすれば
       S[0:K] は不変のまま S[K+1] を変えられるからである。
       従って、K >= N/2 であり、K を大きくしていって条件を満たさなくなる点を探す。
     */
    int il, ir;
    char c;
 
    if( N % 2 == 0 ){
        ans = N / 2;
        il = N / 2 - 1;
        ir = N / 2;
        c = S[il];
    }else{
        ans = (N - 1) / 2;
        il = ir = (N - 1) / 2;
        c = S[il];
    }
    while( il >= 0 && ir < N && S[il] == c && S[ir] == c ){
        ans++;
        il--;
        ir++;
    }
    

    // 解説PDFの実装
    /*for( int i = 0; i < N-1; ++i ){
        if( S[i] != S[i+1] ){
            int tmp = max( i+1, N-i-1 );
            ans = min( ans, tmp );
        }
    }
    if( ans == INT_MAX ) ans =  N;  // 文字列が全て同じとき
    */

    cout << ans << endl;

    return 0;
}