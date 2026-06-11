#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  string s; 
  cin >> s;
  
  int zero = 0, one = 0;
  int n = s.size();
  rep(i,n)
  {
    if(s[i] == '0')
    {
      zero++;
    }else{
      one++;
    }     
  }
  
  cout << n - abs(zero - one) << endl;
}