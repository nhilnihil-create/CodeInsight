#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
  string S;
  
  cin >> S;
  int a,b,c,d;
  a = S.at(0) - '0';
  b = S.at(1) - '0';
  c = S.at(2) - '0';
  d = S.at(3) - '0';
  
  string result_string = "";
  int result;
  for (int i = 0; i < (1 << 3); i++)
  {
    bitset<3> s(i);
    if (s.test(0))
    {
      result = a + b;
      result_string = to_string(a) + "+" + to_string(b); 
    }
    else
    {
      result = a - b;
      result_string = to_string(a) + "-" + to_string(b);
    }
    if (s.test(1))
    {
      result = result + c;
      result_string = result_string + "+" + to_string(c); 
    }
    else
    {
      result = result - c;
      result_string = result_string + "-" + to_string(c); 
    }
    if (s.test(2))
    {
      result = result + d;
      result_string = result_string + "+" + to_string(d); 
    }
    else
    {
      result = result - d;
      result_string = result_string + "-" + to_string(d); 
    }
    if(result == 7)
    {
      cout << result_string << "=7" << endl;
      return 0;
    }
  }
  return 0;
}