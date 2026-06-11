#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

bool isPrime(int a) {
    if (a == 1) return false;
    for (int i = 2; i * i <= a; i++) {
        if(a % i == 0) return false;
    }
    return true;
}


void solve()
{
  int n;
  cin >> n;

  vector<int> ans{2};
  int num = 1;
  while(ans.size() < n)
  {
    num += 10;
    if (isPrime(num)) ans.emplace_back(num);
  }
  for(const auto& v : ans)
  {
    cout << v << " ";
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}