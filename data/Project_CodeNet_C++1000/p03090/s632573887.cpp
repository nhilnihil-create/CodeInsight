#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>> vec;
  int m, sum;
  if (n%2==0) {
    sum=n+1;
    m=(n-2)*n/2;
  } else {
    sum=n;
    m=(n-1)*(n-1)/2;
  }
  cout<<m<<endl;
  vector<vector<bool>> used(n+5,vector<bool>(n+5,false));
  for (int i = 1; i <= n; ++i)
  {
    used[i][i]=true;
  }
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n ; ++j)
    {
      if (used[i][j]) continue;
      if (i+j==sum) continue;
      cout<<i<<" "<<j<<endl;
      used[i][j]=true;
      used[j][i]=true;
    }
  }

  for (int i = 0; i < vec.size(); ++i)
  {
    for (int j = 1; j <=n ; ++j)
    {
      if (vec[i].first==j||vec[i].second==j) continue;
      cout<<vec[i].first<<" "<<j<<endl;
    }
  }
}