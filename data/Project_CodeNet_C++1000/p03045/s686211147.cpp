#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n, m;
vector<vector<int>> e(101010, vector<int>(0));
int per[101010];

void dfs(int a, int d)
{
  if(per[a] != 0) return;
  per[a] = d;
  
  for(auto x : e[a])
  {
    dfs(x, d);
  }
  return;
}

int main()
{
  cin >> n >> m;
  
  rep(i, m)
  {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    e[y].emplace_back(x);
    e[x].emplace_back(y);
  }
  
  //rep(i, n) { for(auto x : e[i]) cout << x << " "; cout << endl;}
  
  int c = 0;
  rep(i, n)
  {
    if(per[i]== 0)
    {
      c++;
      dfs(i, c);
    }
    //rep(j, n) cout << per[j] << " "; cout << endl;
  }
  
  cout << c << endl;
  
  return 0;
}