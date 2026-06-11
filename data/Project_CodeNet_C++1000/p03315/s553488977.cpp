#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve(std::string S){
  int ans = 0;
  for (int i = 0; i < 4; i++)
  {
    ans += (S[i] == '+') ? 1 : -1;
  }
  cout << ans << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
