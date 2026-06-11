#include<bits/stdc++.h>
using namespace std;
int  main()
{ string s;
 cin>>s;
 int c1=0;
 for(int i=0;i<4;i++)
 {  if(s[i]=='+')
         c1++;
     else
         c1--;
 }
       cout<<c1;
     
}