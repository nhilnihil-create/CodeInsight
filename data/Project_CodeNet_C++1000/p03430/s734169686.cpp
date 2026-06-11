#include <bits/stdc++.h>

using namespace std;

typedef long long I64;

const double EPS = 1e-6;
const double PI  = acos(-1);
const int NMAX = 303;

int d[NMAX+2][NMAX+2][NMAX+2];

int max(int a, int b, int c)
{
    return max(max(a,b), c);
}

int max2(int a, int b, int c)
{
    return max(max(a,b), c);
}

int main()
{
    int N, K;
    string str;
    cin >> str;
    N = str.size();
    if( N == 1 ) {
        cout << "1\n";
        return 0;
    }
    str = "#" + str + "*";
    cin >> K;
    int Ans = 1;
    for( int i = 1;  i <= N;  ++i ) {
        for( int j = N;  i < j;  --j ) {
            d[i][j][0] = max2( d[i - 1][j][0], d[i][j + 1][0], d[i - 1][j + 1][0] + (str[i] == str[j]) );
            Ans = max( Ans, d[i][j][0] * 2 + (i + 2 == j) );
            Ans = max( Ans, d[i][i + 1][0] * 2 );
            for( int k = 1;  k <= K;  ++k ) {
                if( str[i] == str[j] )
                    d[i][j][k] = max2( d[i - 1][j][k], d[i][j + 1][k], d[i - 1][j + 1][k] + 1 );
                else
                    d[i][j][k] = max2( d[i - 1][j][k],
                                      d[i][j + 1][k],
                                      d[i - 1][j + 1][k - 1] + 1 );
                Ans = max(Ans, d[i][j][k] * 2 + (i + 2 == j));
            }
        }
    }
    cout << Ans << '\n';
    return 0;
}
