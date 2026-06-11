#include <bits/stdc++.h>
using namespace std;

bool pal(int a)
{
    string s;
    s=to_string(a);
    int n=s.size();
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-1-i])
            return false;
    }
    return true;
}



int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    if(a>b)
        swap(a,b);
    for(int i=a;i<=b;i++)
    {
        if(pal(i))
            ++ans;
    }
    cout<<ans;
    return 0;
}


