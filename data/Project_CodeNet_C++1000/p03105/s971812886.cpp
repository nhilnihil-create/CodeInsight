#include<bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main()
{
    cin>>a>>b>>c;
    if(a>b){
        cout<<0;
        return 0;
    }
    ans=b/a;
    if(ans>=c)
        cout<<c<<endl<<endl;
    else
        cout<<ans<<endl<<endl;
    return 0;
}