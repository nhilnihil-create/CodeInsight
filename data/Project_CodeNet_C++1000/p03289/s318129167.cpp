#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count=0,i;
   string s;
   cin>>s;

   if(s[0]!='A')
   {
       cout<<"WA";
       return 0;
   }
    for(i=2;i<=s.size()-2;i++)
    {
        if(s[i]=='C')
            count++;
    }
    if(count!=1)
    {
        cout<<"WA";
        return 0;
    }
    for(i=0;i<s.size();i++)
    {
        if(s[i]>64 && s[i]<91)
        {
            if(s[i]!='A' && s[i]!='C')
            {
                //cout<<s[i]<<" ";
               cout<<"WA";
                return 0;
            }
        }
    }
    cout<<"AC";

}
