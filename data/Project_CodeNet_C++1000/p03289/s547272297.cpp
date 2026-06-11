#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,cou=0,index,n;
    string s;
    cin>>s;
    n=s.length();
    if(s[i]!='A')
    {
        cout<<"WA";
        return 0;
    }
    for(i=2;i<n-1;i++)
    {
        if(s[i]=='C')
        {
            cou++;
            index=i;
        }
    }
    if(cou!=1)
    {
        cout<<"WA";
        return 0;
    }
    for(i=1;i<n;i++)
    {
        if(i!=index)
        {
            if(!islower(s[i]))
            {
                cout<<"WA";
                return 0;
            }
        }
    }
    cout<<"AC";
    return 0;
}
