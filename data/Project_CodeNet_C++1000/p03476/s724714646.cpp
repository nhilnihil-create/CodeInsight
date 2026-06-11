#include <bits/stdc++.h>


#define dhai_machli ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

const int N = 2e5 + 10;


bool f[100001];
int c[100002];

int n, l, r;

using namespace std;

int main()
{



   dhai_machli;



   for ( int i = 2; i * i <= 100000; i ++) if (! f [ i ]) 
      for ( int j = i * i ; j <= 100000; j += i )
            f[ j ] = true ;
   for ( int i = 3; i <= 100000; i += 2) 

      if (! f [ i ] && ! f [( i + 1) / 2]) c [ i ]++;

   for ( int i = 3; i <= 100000; i ++) c [ i ] += c [i - 1];

      
   cin >> n;
   while (n--)
   {
      cin >> l >> r;

      cout << c[r] - c[l - 1] << endl;
   }


   return 0;
}
