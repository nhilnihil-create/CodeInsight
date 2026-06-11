#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,k,na,nb,nc,ans;
    cin>>a>>b>>c>>k;
    if(k%2==0)
    ans=a-b;
    else
        ans = b-a;

    if(abs(ans)>1000000000000000000)
        cout<<"unfair";
    else
    cout<<ans;
    return 0;
}

