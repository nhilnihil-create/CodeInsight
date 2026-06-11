#include<bits/stdc++.h>
using namespace std;


int main(){
  double N;
  cin >> N;
  for(double h=1;h<=3500;++h){
    for(double n=2;n<=3500;++n){
      long long a=N*h*n;
      long long b=4*h*n-N*n-N*h;
      if(b>0 && a%b==0){
        auto w=a/b;
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }
  return 0;
}
