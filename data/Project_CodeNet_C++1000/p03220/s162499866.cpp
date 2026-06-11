#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,T,A,kyuuden=0;
    double Atonosa=100000;
  cin >> N >> T >> A;
  for(int i=0;i<N;i++){
    int H;
    double kion;
    cin >> H;
    kion=T-H*0.006;
    if(Atonosa>abs(A-kion)){
      Atonosa=abs(A-kion);
      kyuuden=i+1;
    }
  }
  cout << kyuuden << endl;
}