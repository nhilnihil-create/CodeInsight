#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
 ll X;
 cin>>X;
 ll ans=0;
 for(int i=1; i<35; i++){
     int cnt=i;
     for(int j=0; j<11; j++){
         cnt*=i;
         if(cnt<=X){
             if(ans<cnt){
                 ans=cnt;
             }
         }
         if(X<cnt){
             j+=40;
         }    
     }
     } 
     cout<<ans<<endl;
 }

