#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j;
   string s;
    long long int x=10000;
   cin>>s;
   for(i=0;i+2<s.size();i++)
   {
       string q;
       for(j=i;j<i+3;j++)
       {
           q+=s[j];
       }
       long long int l=stoi(q);
       //cout<<l<<endl;
       x=min(x,abs(753-l));
   }
    cout<<x;
}
