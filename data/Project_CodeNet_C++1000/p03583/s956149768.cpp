#include <bits/stdc++.h>

using namespace std;



int main(){
 long long m;
  cin >> m;
 
 for(long long h=1;h<=3500;h++){
  for(long long n=1;n<=3500;n++){
     long long w=m*h*n;
     long long d=4*h*n-m*n-m*h;
    if(d>0&&w%d==0) {
     cout << h << " " << n << " " << w/d << endl;
      return 0;
    }
  } 
 }
}