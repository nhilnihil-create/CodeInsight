#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string YES = "Yes";
const string NO = "No";

int main()
{
  ll A;
  scanf("%lld",&A);
  ll B;
  scanf("%lld",&B);
  ll C;
  scanf("%lld",&C);
  if (A==B&&B==C) cout << YES << endl;
  else cout << NO << endl;

  return 0;
}
