#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(int n)
{
  string s="Christmas";
  cout<<s;
  for(short i=25-n;i>0;i--)
  {
    cout<<" Eve";
  }
}

int main()
{
  short n;
  cin>>n;
  void (*ptr)(int);
  ptr=&solve;
  (*ptr)(n);
  return 0;
}