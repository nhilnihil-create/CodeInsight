#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int a,b;
  cin >> a >> b;
  int c=max(a,b);
  if(c>8)
    cout << ":(" << endl;
  else
    cout << "Yay!" << endl;
}
