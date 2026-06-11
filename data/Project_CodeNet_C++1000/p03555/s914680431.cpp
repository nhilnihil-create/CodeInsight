#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  string t;

  cin>>s;
  cin>>t;

  reverse(s.begin(),s.end());
  printf("%s",(s==t)?"YES":"NO");

  return 0;
}