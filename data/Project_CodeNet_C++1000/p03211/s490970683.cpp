#include <bits/stdc++.h>
using namespace std;
int main() {
  string S; cin >> S;
  int ans=999,N=S.size();
  
  for(int i=0; i<N-2; i++) {
    int num = (S.at(i)-'0')*100 + (S.at(i+1)-'0')*10 + S.at(i+2)-'0';
    ans = min(ans,abs(num-753));
  }
  cout << ans << endl;
}