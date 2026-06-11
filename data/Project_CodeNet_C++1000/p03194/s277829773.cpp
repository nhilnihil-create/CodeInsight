#include <bits/stdc++.h>

#define REP(i ,n) for(int i=0 ;i < n; i++)
#define REPB(i ,n) for(int i=n; i >= 0; i--)
#define FOR(i ,m ,n) for(int i=m; i < n; i++)
#define FORB(i, m, n) for(int i=m; i>= m; i--)
#define ll long long
#define pb push_back
#define popb pop_back
using namespace std;

long beki(long a, long b){
  int t = 1;
  REP(q, b) t= t *  a;
  return t;
}

int main(){
   long n,p;
   cin >> n >> p;
   long ans = 1;
   double m = 1.0 / n;
   long s = pow(p, m) + 2;
   if(n == 1){
       ans = p;
     }else{
   FOR(i, 2, s){
     long  bk = pow(i , n);
    if(p % bk == 0) ans = i;
         } 
}
     cout << ans << endl;
}
