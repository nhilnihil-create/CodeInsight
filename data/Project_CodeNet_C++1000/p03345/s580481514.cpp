#include <bits/stdc++.h>
using namespace std;


 
int main() {
//cin>>str;
//cout<<str<<endl;
  long long taka, nakaz, hiku, K;
  long long kaisuu;
  long long twa, nwa, hwa;
  
  cin>>taka>>nakaz>>hiku>>K;
  long long judge = 0;
  if(K%2 == 0){
    judge = taka - nakaz;
  }else{
    judge = nakaz - taka;
  }
  cout<<judge<<endl;
}