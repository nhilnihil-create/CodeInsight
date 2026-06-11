#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int ans;
vector<int> a(5);

void dfs(vector<int> &x, vector<bool> &y){
  if (x.size() == 5)
  {
    int temp = 0;
    for (int i = 0; i < 4; i++)
    {
      temp += ((x[i] + 9) / 10) * 10; 
    }
    temp += x.back();
    ans = min(ans, temp);
    return;
  }
  
  for (int i = 0; i < 5; i++)
  {
    if (!y[i])
    {
      continue;
    }
    x.push_back(a[i]);
    y[i] = false;
    dfs(x, y);
    x.pop_back();
    y[i] = true;
  }
  
}

int main() {
  a.resize(5);
  for (int i = 0; i < 5; i++)
  {
    cin >> a[i];
  }
  vector<int> x;
  vector<bool> y(5, true);
  ans = 700;
  dfs(x, y);
  cout << ans << endl;
  return 0;
}
