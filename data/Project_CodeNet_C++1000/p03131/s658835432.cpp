#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define INF 999999999
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using llong = long long;
using namespace std;

int main(){
   llong k,a,b,ans=0,trade,amari;
   cin >> k >> a >> b;
   if(b-a>2){
       trade = (k-a+1)/2;
       if((k-a+1)%2) amari=1;
       else amari=0;
       ans = trade*(b-a)+a+amari;
   }else{
       ans = k+1;
   }
   cout << ans << endl;
   return 0;
}