#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
  ll N;
  cin>>N;
  for(ll i=1; i<100000; i++){
      if(N<=i*i){
          if(i*i==N){
              cout<<i*i<<endl;
            	break;
          }
          else{
              cout<<(i-1)*(i-1)<<endl;
            break;
          }
      }
  }
}