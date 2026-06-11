#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
using ll=long long;
int main()
{
    int a,b,c,rafi=0,ans;
    cin>>a>>b>>c;
    ans=b/a;
    if(c>ans)
    {
        cout<<ans<<endl;
    }
    else{
        cout<<c<<endl;
    }
    return 0;
}
