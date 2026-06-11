#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans=0;
  for(int i=0;i<3;i++){
    int A=S.at(i)-'0';
    ans+=A;
  }
  cout << ans << endl;
}