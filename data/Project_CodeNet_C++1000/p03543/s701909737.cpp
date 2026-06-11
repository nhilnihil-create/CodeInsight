#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i,su=0;
    cin>>s;
    for(i=1;i<4;i++)
    {
        if(s[i]==s[i-1]&&s[i]==s[1])
            su++;
    }
    cout<<(su>=2?"Yes":"No")<<endl;
}
