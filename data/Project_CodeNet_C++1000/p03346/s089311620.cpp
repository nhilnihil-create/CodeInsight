#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  int n;
  cin>>n;
  vector<int> p(n);
  unordered_map<int,int> mp;
  for (int i = 0; i < n; ++i)
  {
    int tmp;
    cin>>tmp;
    mp[tmp]=i;
  }
  int cnt=1, ans=0;
  for (int i = 0; i < n-1; ++i)
  {
    if (mp[i+1]<mp[i+2]) {
      cnt++;
    } else {
      ans = max(ans,cnt);
      cnt = 1;
    }
  }
  ans = max(ans,cnt);
  cout<<n-ans<<endl;
}