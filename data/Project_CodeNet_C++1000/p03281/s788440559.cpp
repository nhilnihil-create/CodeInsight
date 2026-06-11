#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int how_many_divs(int n)
{
  int cnt=0;
  for (int i = 1; i <= n; ++i)
  {
    if(n%i==0) cnt++;
  }
  return cnt;
}

int main()
{
  int n;
  cin>>n;
  int cnt=0;
  for (int i = 1; i <= n; i+=2)
  {
    if(8==how_many_divs(i)) cnt++;
  }
  cout<<cnt<<endl;
}