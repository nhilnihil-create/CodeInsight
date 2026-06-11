#include <bits/stdc++.h>
using namespace std;
#define LONGLONGMAX 9223372036854775807
#define LONGLONGMIN -9223372036854775807
#define INTMAX 32767
#define INTMIN -32767
#define ROUNDUP(divisor,dividend) (divisor + (dividend - 1)) / dividend
string s,t;
int main(){
  cin >> s;
  t=s;
  reverse(t.begin(),t.end());
  cout << (s.length()==2 ? s : t) << endl;
}
