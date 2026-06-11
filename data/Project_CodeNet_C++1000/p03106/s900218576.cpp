#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  int A, B, K; cin >> A >> B >> K;
  vector<int> ans;

  for(int i = 1; i < min(A,B)+1; i ++) {
    if (A % i == 0 && B % i == 0) {
      ans.push_back(i);
    }
  }



  cout << ans[ans.size()-K] << endl;
  return 0;
}