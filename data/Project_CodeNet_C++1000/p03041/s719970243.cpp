#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#define rep2(i,x,y) for (int i = x; i < (y); ++i)
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  s[k-1] = tolower(s[k-1]);
  cout << s << endl;
  return 0;
}