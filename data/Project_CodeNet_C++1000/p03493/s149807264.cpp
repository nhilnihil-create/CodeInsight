#include<iostream>
#include<string>
using namespace std;
int main()
{
  int i,res=0;
  string s;
  cin >> s;
  for(i=0;i<3;i++)
    if(s[i]=='1')
      res++;
  cout << res << endl;
  return 0;
}