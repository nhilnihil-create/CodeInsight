#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N;
  string A,B,C;
  cin >> N >> A >> B >> C;

  set<int> S;
  int ans = 0;
  for(int i = 0;i < N;i++) {
    S.insert(A.at(i));
    S.insert(B.at(i));
    S.insert(C.at(i));
    if(S.size() != 1) ans += S.size() - 1;
    while(!S.empty()) S.erase(S.begin());
  }

  cout << ans << endl;


}
