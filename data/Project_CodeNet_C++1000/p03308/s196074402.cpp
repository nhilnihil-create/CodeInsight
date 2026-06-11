#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N;
   cin>>N;
   ll A,s=10000000000,b=-100;
   rep(i,N){
       cin>>A;
       s=min(s,A);
       b=max(b,A);
   }
    cout<<b-s<<endl;
}