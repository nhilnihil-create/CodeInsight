#include <iostream>
using namespace std;
int main(){
  int n;cin>>n;
  long long a[n];
  for(int i = 0; n > i; i++){
    cin>>a[i];
  }
  long long ans = 0;
  long long sm = 0;
  long long smx = 0;
  int prev = 0;
  for(int i = 0; n > i; i++){
    sm += a[i];
    smx ^= a[i];
    while(sm != smx){
      sm -= a[prev];
      smx ^= a[prev];
      prev++;
    }
    ans += i-prev+1;
  }
  cout << ans << endl;
}