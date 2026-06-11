#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin >> N;

  for(long long h=1;h<=3500;h++){
    for(long long n=h;n<=3500;n++){
      long long a=N*h*n;
      long long b=4*h*n-N*h-N*n;
      if(b<=0)  continue;
      if(a%b!=0)  continue;
      cout << h << " " << n << " " << a/b << endl;
      return 0;
    }
  }

  return 0;
}