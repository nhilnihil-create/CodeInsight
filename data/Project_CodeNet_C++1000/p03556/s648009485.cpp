#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long ans=0;
  long long i=1;
  while(ans+i<=n){
    ans+=i;
    i+=2;
  }
  cout << ans << endl;
}