#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int count =0;
    cin>>s;
    string ans="AC";
    if(s[0]!='A')
    {
        ans="WA";
    }
    int a=s.length();
    for(int i=1;i<a;i++)
    {
        if(isupper(s[i]))
        {
            if(i==1|| i==a-1||s[i]!='C')
            {
                ans="WA";
            }
            count++;
        }
    }

    if(count!=1)
    {
       ans= "WA";
    }
    cout<<ans<<"\n";
    return 0;
}