#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a[5];
  int k;
  rep(i, 5){
    cin >> a[i];
  }
  cin >> k;
  rep(i, 5){
    rep(j, 5){
      if(abs(a[i] - a[j]) > k){
        cout << ":(" << endl;
        return 0;
      }
    }
  }
  cout << "Yay!" << endl;
  return 0;
}
