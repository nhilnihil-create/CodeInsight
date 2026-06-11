#include <bits/stdc++.h>
using namespace std;
 
int n,k;
 
int main(){
  cin >> n >> k;
  
  double res = 0;
  
  for(int i = 1; i <= n; ++i){
    //cout << i << " " << res << endl;
    if(i >= k){
      double cou = 1.0 / n;
      res += cou;
    }else{
      double  cou = 1;
      int c = i;
      while(c < k){
        cou /= 2;
        c *= 2;
      }
      res += cou / n;
    }
  }
  
  printf("%.12f\n",res);
}