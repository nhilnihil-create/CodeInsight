#include<bits/stdc++.h>
using namespace std;

int main()
{
string s;
int zero=0,one=0,a,i;
cin>>s;
for(i=0;i<s.size();i++)
{
   a=s[i]-'0';
   if(i%2==1&&a==0)
    zero++;
   else if(i%2==0&&a==1)
    zero++;

}

for(i=0;i<s.size();i++)
{
   a=s[i]-'0';
   if(i%2==1&&a==1)
    one++;
   else if(i%2==0&&a==0)
    one++;

}
cout<<min(zero,one);

}
