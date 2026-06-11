#include<bits/stdc++.h>
using namespace std;

int main(){
  double a,k;
  cin >> a >> k;
  double ans = 0;
  for(int i=1;i<=a;i++){
    if(i > k){
      ans += 1 ;
      //cout << '!';
    }else{
      double n = k/i;
      int nn = 1;
      while(n > 1){
        n /= 2;
        nn *= 2;
      }
      //cout << nn << "#";
      ans += 1.0 / nn;
    }
  }
  double s = ans / a;
  cout << setprecision(10);
  cout << s << endl;
  return 0;
}