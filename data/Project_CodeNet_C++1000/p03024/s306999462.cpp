#include<bits/stdc++.h>
using namespace std;
char s[15];
int cnt;
int main()
{
    cin>>s;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='x')
        {
            cnt++;        
        }
    }
    if(cnt>7)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}