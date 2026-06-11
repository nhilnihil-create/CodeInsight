#include<bits/stdc++.h>
using namespace std;
int main()
{
string S;
int a=0;
  
cin >> S;
  
  for(int i=0;i<4;++i)
  {
  if(S[i]=='+') ++a;
  else if(S[i]=='-') --a;
  }

cout << a << endl;

return 0;
}