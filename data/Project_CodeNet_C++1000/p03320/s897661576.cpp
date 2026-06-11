#include<bits/stdc++.h>
using namespace std;
int sum(long long n)
{
  if(n) return sum(n/10) + n%10;
  return 0;
}
bool cmp(pair<long long, int> a, pair<long long, int> b)
{
  return a.first*b.second < a.second*b.first;
}
int main()
{
  int K; scanf("%d", &K);
  vector<pair<long long, int> > V;
  long long pow10 = 1;
  for(int i=0; i<=12; ++i)
  {
    for(int j=1; j<=999; ++j)
    {
      long long targ = j*pow10 + (pow10-1);
      V.emplace_back(targ, sum(targ));
    }
    pow10 *= 10;
  }
  sort(V.rbegin(), V.rend());
  V.resize(unique(V.begin(), V.end())-V.begin());
  //for(auto x: V) printf("%lld %d\n", x.first, x.second);
  vector<long long> ans;
  pair<long long, int> mv = make_pair(999999999999999LL, 1);
  for(auto x: V)
  {
    if(!cmp(mv, x))
    {
      ans.push_back(x.first);
      mv = x;
    }
  }
  reverse(ans.begin(), ans.end());
  ans.resize(K);
  for(auto x: ans) printf("%lld\n", x);
}