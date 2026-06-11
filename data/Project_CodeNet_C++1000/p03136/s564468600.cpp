#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) cin >> l.at(i);

  sort(l.begin(), l.end(),greater<int>());

  // rep(i, n) cout << l.at(i);
  int sum = 0;


  for (int i = 1; i < n;i++){
    sum += l.at(i);
  }

  if(l.at(0) < sum)
    cout << "Yes";
  else
  {
    cout << "No";
  }

}
