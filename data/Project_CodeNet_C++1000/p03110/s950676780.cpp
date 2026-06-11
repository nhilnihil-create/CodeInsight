#include<bits/stdc++.h>
using namespace std;

int main(){
  cout << fixed << setprecision(10);
  int N;cin>>N;
  double happy=0;
  for(int i=0;i<N;i++){
    double X;string U;cin>>X>>U;
    if(U=="JPY") happy+=X;
    else happy+=X*380000.0;
  }
  cout<<happy<<endl;
}