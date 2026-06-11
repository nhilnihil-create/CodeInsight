#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int a, b, k;
  cin >> a >> b >> k;
  set<int> s;
  for (int i = a; i < a + k && i <= b; i++)
    s.insert(i);
  for (int i = b; i > b - k && i >= a; i--)
    s.insert(i);
  for (auto itr = s.begin(); itr != s.end(); itr++)
    cout << *itr << endl;
}
