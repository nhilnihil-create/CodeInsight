#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int mid = a + b + c - max(max(a, b), c) - min(min(a, b), c);
  

  cout << max(max(a, b), c) * 10 + mid + min(min(a, b), c);

   return 0;
}