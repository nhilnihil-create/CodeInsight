#include <bits/stdc++.h>
using namespace std;
main(){
  int N,A,B;
  cin >> N >> A >> B;
  int ans=0;
  for(int i=0;i<=N;i++){
    int sum = 0;
    int x=i;
    for(int j=0;j<5;j++){
      sum += x%10;
      x /= 10;
    }
    if(A<=sum && sum<=B) ans+=i;
  }
  cout << ans << endl;
}