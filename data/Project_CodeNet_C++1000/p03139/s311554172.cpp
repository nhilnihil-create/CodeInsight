#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, A, B;
  cin >> N >> A >> B;
  cout << (A > B ? B : A) << ' ' << (A + B - N >= 0 ? A + B - N : 0) << endl;
}
