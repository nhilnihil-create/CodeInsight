#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int JPY=0;
  int64_t BTC=0;
  double x;
  string u;
  for(int i=0; i<N; i++){
    cin >> x >> u;
    if(u=="JPY"){
      JPY+=(int)x;
    }
    else{
      BTC+=(int64_t)(x*100000000);
    }
  }
  double BTCd;
  BTCd=BTC*380000;
  BTCd/=100000000;
  double JPYd=(double)JPY;
  cout << setprecision(8) << JPYd+BTCd << endl;
}
  