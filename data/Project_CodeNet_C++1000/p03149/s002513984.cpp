#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v(4), a = {1, 4, 7, 9};
  for(int i = 0; i < 4; i++)
    cin >> v.at(i);
  sort(v.begin(), v.end());
  if(v == a)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
