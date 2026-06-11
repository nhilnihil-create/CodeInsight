#include <bits/stdc++.h>
using namespace std;


int main()
{
    string S;
    cin >> S;


    int n = S.size();
    int ans = INT_MAX;
    for( int i = 0; i < n-1; ++i ){
        if( S[i] != S[i+1] ){
            int tmp = max( i+1, n-i-1 );
            ans = min( ans, tmp );
        }
    }
    if( ans == INT_MAX ) cout <<  n  << endl;  // 文字列が全て同じとき
    else                 cout << ans << endl;

    return 0;
}