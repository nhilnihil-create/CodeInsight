#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,i,ci=0,h=0;
    cin>>a>>b;
    string s;
    cin>>s;
    for(i=0; i<s.size(); i++)
    {
        if(int(s[i])>=48 && int(s[i])<=58)
        ci++;
        if(s[i]=='-')
        h++;
    }
    
    if(s[a]=='-'&& h==1 && ci==(a+b))
    cout<<"Yes";
    else
    cout<<"No";

    return 0;
}
