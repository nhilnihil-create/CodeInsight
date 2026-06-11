// ABC_120_B

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, k;
  cin >> a >> b >> k;

  auto maxi = max(a, b);
  vector<int> vec;
  
  for (int i = 1; i <= maxi; ++i) {
    if((a%i==0) && (b%i==0)) vec.push_back(i);
    else continue;
  }

  sort(vec.rbegin(), vec.rend());

  cout << vec[k-1] << "\n";

  return 0;
}
