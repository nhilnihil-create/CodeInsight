/**
                  ▄█▀ ▀█▀ ▄▀▄ █▀ █▄█▄█ ▄▀▄ █▀ ▄█▀
                  <⇋⇋⇋⋛∰≓⊂(⌒,_ゝ⌒)⊃≓∰⋛⇋⇋⇋>

            ♔♕♖♗♘♙ ☜❷☞✪ ィℋ६ ≈ ᗫẵℜℵĬŊĞ ✪☜❷☞ ♚♛♜♝♞♟
            ♔♕♖♗♘♙                             ♚♛♜♝♞♟
                      ˙·٠•●♥ Ƹ̵̡Ӝ̵̨̄Ʒ ♥●•٠·˙

**/

#include <bits/stdc++.h>

#define sz(s) s.size()
#define pb emplace_back
#define fr first
#define sc second
#define mk make_pair
#define all(s) s.begin(), s.end()

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9 + 7;

int n, sum, a[N];
vector < int > b;
vector < pair < int, int > > s;

main()
{
   cin >> n;
   for( int i = 1; i <= n; i++ )
      cin >> a[i], b.pb( a[i] );

   sort( all( b ) );

   for( int i = 1; i <= n; i++ )
   {
      int pos = lower_bound( all( b ), a[i] / 2 ) - b.begin() - 3;
      pos = max( 0, pos );
      int p = inf, l = 0;
      for( int j = pos; j <= min( pos + 3, n - 1 ); j++ )
         if( abs( a[i] - b[ j ] - b[ j ] ) < p )
            l = b[ j ], p = abs( a[i] - b[ j ] - b[ j ] );
      s.pb( mk( a[i], l ) );
   }
   pair < int, int > v, q;
   sort( all( s ) );
   v = s[ sz(s) - 1 ];
   cout << v.fr << ' ' << v.sc << endl;
}
