#include <bits/stdc++.h>
using namespace std;
int main()
{
string str;
cin>>str;
int n=str.length();
int i;
int count=0;
for(i=0; i<n; i++)
{
  if(str[i]=='o')
  count++;
}
if(15-n+count>=8)
cout<<"YES";
else cout<<"NO";
}