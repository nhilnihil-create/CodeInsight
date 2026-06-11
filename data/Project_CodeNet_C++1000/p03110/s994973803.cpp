#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  long double J=0,B=0;
  for(int i=0;i<N;i++){
    long double X;
    string S;
    cin>>X>>S;
    if(S=="JPY"){
      J+=X;
    }
    else{
      B+=X;
    }
  }
  B*=380000.0;
  B+=J;
  cout<<fixed<<setprecision(15);
  cout<<B<<endl;
}