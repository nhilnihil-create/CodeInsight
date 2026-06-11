#include <bits/stdc++.h>
using namespace std;

int main(){
  double n , k;
  cin >> n >> k ;
  double ans =0;
  
  for(int i=1;i<=n;i++){
    int tmp = i;
  double  count = 1.0/n;
    while(k>tmp){
      tmp *= 2;
      count /= 2;
    }
    ans += count ;
  }
  
  cout << setprecision(15) << ans << endl;
}



