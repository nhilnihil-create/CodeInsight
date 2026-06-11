#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int ans=0;
  
  for(int i=1; i<=N; i++){
    int wa =0;
    int ii = i;
    for(int j=0; j<5; j++){
      wa += ii%10;
      ii /=10;
    }
    if(A<=wa && wa<=B)ans+=i;
  }
  
  cout << ans << endl;
}
