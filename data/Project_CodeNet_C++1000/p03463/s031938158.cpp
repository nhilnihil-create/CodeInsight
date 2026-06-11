#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  bool ans = false;
  
  if((A == 1 && B == 2) || (A == N-1 && B == N))
    ans = true;
  else if(A % 2 != B % 2)
    ans = true;
  
  if(ans) cout << "Borys" << endl;
  else cout << "Alice" << endl;
}
    