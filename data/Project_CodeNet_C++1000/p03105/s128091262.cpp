#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,ans=0;
    cin>>a>>b>>c;
    ans=b/a;
    ans=min(c,ans);
    cout<<ans;
    return 0;
}
