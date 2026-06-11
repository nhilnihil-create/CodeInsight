#include <bits/stdc++.h>
using namespace std;
int main()
{
  char s[4];
  int i;
  int sum=0;
  cin>>s;
  for(i=0;i<4;i++){
    if(s[i]=='+') sum++;
    if(s[i]=='-') sum--;
  }
  cout<<sum;
}