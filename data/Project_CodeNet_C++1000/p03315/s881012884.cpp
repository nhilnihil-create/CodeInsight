 #include<bits/stdc++.h>
using namespace std;
int main()
{
  char s[4];
  int count=0;
  cin>>s;
  for(int i=0;i<strlen(s);i++)
  {
    if(s[i]=='+')
    count++;
    else if(s[i]=='-')
    count--;
  }
  cout<<count<<endl;
}