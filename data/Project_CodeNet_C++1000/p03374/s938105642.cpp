/**
                  ▄█▀ ▀█▀ ▄▀▄ █▀ █▄█▄█ ▄▀▄ █▀ ▄█▀
                  <⇋⇋⇋⋛∰≓⊂(⌒,_ゝ⌒)⊃≓∰⋛⇋⇋⇋>

            ♔♕♖♗♘♙ ☜❷☞✪ ィℋ६ ≈ ᗫẵℜℵĬŊĞ ✪☜❷☞ ♚♛♜♝♞♟
            ♔♕♖♗♘♙                             ♚♛♜♝♞♟
                      ˙·٠•●♥ Ƹ̵̡Ӝ̵̨̄Ʒ ♥●•٠·˙
**/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <math.h>

#define sz(s) s.size()
#define pb push_back
#define fr first
#define sc second
#define mk make_pair
#define int long long
#define all(s) s.begin(), s.end()

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e9 + 7;

int n, c, ans1[N], ans2[N], ans3, ans4, x[N], a[N], suf[N], pref[N];

main()
{
   cin >> n >> c;
   for( int i = 1; i <= n; i++ )
   {
      cin >> x[i] >> a[i];
      pref[ i ] = a[i];
      pref[ i ] += pref[ i - 1 ];

      ans1[ i ] = ans1[ i - 1 ];
      if( pref[ i ] - x[ i ] > ans1[ i ] )
         ans1[ i ] = pref[ i ] - x[ i ];

   }
   for( int i = n; i > 0; i-- )
   {
      suf[ i ] = a[i];
      suf[ i ] += suf[ i + 1 ];

      ans2[ i ] = ans2[ i + 1 ];
      if( suf[ i ] - c + x[ i ] > ans2[ i ] )
         ans2[ i ] = suf[ i ] - c + x[ i ];
   }

   for( int i = 1; i <= n; i++ )
   {
      ans3 = max( ans3, ans1[ i ] - x[ i ] + ans2[ i + 1 ] );
      ans4 = max( ans4, ans2[ i ] - c + x[ i ] + ans1[ i - 1 ] );
   }
   cout << max( max( ans3, ans4 ), max( ans1[n], ans2[1] ) );

}












