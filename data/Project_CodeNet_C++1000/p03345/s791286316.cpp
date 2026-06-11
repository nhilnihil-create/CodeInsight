#include <bits/stdc++.h>
using namespace std;
#define MAX pow(10,18)
typedef long long ll;

void Calc(ll *A,ll *B,ll *C){
    
    ll a,b,c;
    a = *B + *C;
    b = *A + *C;
    c = *A + *B;
    
    *A = a;
    *B = b;
    *C = c;
}
int main(){
  
  ll A,B,C,K;
  cin >> A >> B >> C >> K;
  
  for(int i=0;i<K;i++){
      Calc(&A,&B,&C);
  }
  if(abs(A - B) > MAX) cout << "Unfair" << endl;
  else cout << A - B << endl;
}