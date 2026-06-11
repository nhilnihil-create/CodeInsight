#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  int i,j,total,sum;
  string s;
  
  cin >> n >> a >> b;
  
  total=0;
  for (i=0;i<=n;++i)
  {
    s = to_string(i);
    sum=0;
    for (j=0;j<s.length();++j)
    {
      sum += (s[j] - '0');
    }
    if (sum>=a && sum<=b)
      total += atoi(s.c_str());
  }
  
  	cout << total << endl;
}