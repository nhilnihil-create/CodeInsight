#include <bits/stdc++.h>
using namespace std;

//3重ループだと間に合わない

int main(){
  int n ;
  cin >> n;
  long long y;
  cin >> y;
  int a =-1; int b=-1; int c=-1;
  
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n-i;j++){
      int k = n-i-j;
      if(10000*i+5000*j+1000*k==y){
       a = i; b=j; c=k;
        break;
      }
    }
  }
   cout << a << ' ' << b << ' ' << c <<endl;
}
