#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)


int main() {
   int A,B,K;
   cin>>A>>B>>K;
   rep(i,100){
       if(A%(100-i)==0&&B%(100-i)==0){
           K--;
       }
       if(K==0){
           cout<<100-i<<endl;
          break;
       }
   }
}