#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
#define PI 3.14159265358979323846264338327950L
typedef unsigned long long uint64;
using namespace std;
int main(){
  int n;
  cin >> n;
   int ans = 0;
  for(int i= 1;i<=n;i+=2){
     int dd = 0;
     for (int X=1;X<=i;++X){
       if(i%X==0){
         ++ dd;
       }
     }
     if(dd==8){
       ++ans;
      }
  }
cout << ans << endl;
return 0;
}