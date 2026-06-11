#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  int N = S.length();
  int odd[2], even[2];
  odd[0] = odd[1] = 0;
  even[0] = even[1] = 0;
  for (int i = 0; i < N; i++)
  {
    if (i % 2 == 0) {
      if (S[i] == '0')
      {
        odd[0]++;
      } else
      {
        odd[1]++;
      }
    } else
    {
      if (S[i] == '0')
      {
        even[0]++;
      } else
      {
        even[1]++;
      }
    }
  }
  cout << min(odd[0] + even[1], odd[1] + even[0]) << endl; 

  return 0;
}
