#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x[5], k;
  for (int i = 0; i < 5; i++)
  {
    cin >> x[i];
  }
  cin >> k;
  for (int i = 0; i < 5; i++)
  {
    for (int j = i + 1; j < 5; j++)
    {
      if (x[j] - x[i] > k)
      {
        cout << ":(" << endl;
        return 0;
      }
      
    }
  }
  
  cout << "Yay!" << endl;
  return 0;
}
