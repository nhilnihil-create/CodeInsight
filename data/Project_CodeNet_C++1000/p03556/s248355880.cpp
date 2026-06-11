#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,ans=0;
  cin >> N;
  for(long long i=0; i<1000000000; i++){
    if(i*i <= N){
      ans = i*i;
    }
  }
  cout << ans << endl;
}
