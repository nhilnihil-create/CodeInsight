#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if(n >= m)
  {
    cout << "0";
    return 0;
  }
  vector <int> x(m);
  for(int i=0; i < m; i++)
    cin >> x[i];
  sort(x.begin(), x.end());
  vector <int> cons(m-1);
  for(int i=1; i < m; i++)
  {
    cons[i-1] = x[i] - x[i-1];
  }
  
  sort(cons.begin(), cons.end());

  int ans = 0;
  for(int i=0; i < m - n; i++)
    ans = ans + cons[i];
  cout << ans;
  return 0;

}