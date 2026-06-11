#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B;
  int ans=0;
  cin >> A>>B;
  N=A;
  
 while(N<=B){
     int d5=N%10;
     int d4=N/10%10;
     int d3=N/100%10;
     int d2=N/1000%10;
     int d1=N/10000;
     if(d5==d1&&d4==d2){
         ans++;
     }
    N=N+1;}
 cout<<ans;    
 
}