#include <bits/stdc++.h>
#include <math.h>
using namespace std;
 
int main() {
  long long n,p;
  cin >> n >> p;
  if (n==1){
    cout << p << endl;
  }
  else{
    long long ans;
    ans=1;
    for (int i = 1; pow(i,n)<=p ; i++) {
      long long tmp;
      tmp=pow(i,n);
      if ( p % tmp ==0){
        ans=i;
      }
    }
    cout << ans << endl;
  }
}