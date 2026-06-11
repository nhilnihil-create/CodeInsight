#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define VEC(TYPE, A, NAME, INIT) vector<TYPE> NAME(A, INIT)
#define VEC2(TYPE, A, B, NAME, INIT) vector<vector<TYPE>> NAME(A, vector<TYPE>(B, (INIT)))

int main()
{
    int n = 0;
    cin >> n;
    VEC(ll, n, x, 0);
    VEC(ll, n, y, 0);
    int mod = -1;
    bool is = true;
    REP(i, n)
    {
        cin >> x[i] >> y[i];
        int m = ( abs( x[i] ) + abs( y[i] ) ) % 2;
        if( i == 0 ) mod = m;
        else if( mod != m ) is = false;
    }
    if( !is ) cout << -1 << endl;
    else
    {
        int k_ = 32;
        int k = k_;
        if( mod == 0 ) ++k;
        cout << k << endl;
        VEC(ll, k, d, 1);
        REP(i,k_) d[i] = ( 1ll << (k_ - i - 1) );
        REP(i, k) cout << d[i] << " ";
        cout << endl;

        REP( i, n )
        {
            ll xx = x[i] + y[i];
            ll yy = x[i] - y[i];
            ll xc = 0;
            ll yc = 0;

            REP(j, k)
            {
                if( xc <= xx && yc <= yy ) 
                {cout << "R"; xc += d[j]; yc += d[j];}
                else if( xc <= xx && yc > yy )
                { cout << "U"; xc += d[j]; yc -= d[j];}
                else if( xc > xx && yc <= yy ) 
                {cout << "D";xc -= d[j]; yc += d[j];}
                else if( xc > xx && yc > yy ) 
                {cout << "L";xc -= d[j]; yc -= d[j];}
            }
            cout << endl;
        }
    }
    
    return 0;
}