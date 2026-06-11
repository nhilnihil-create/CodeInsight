#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,h,w;  cin>>n>>h>>w;
    int ans=0;
    while(n--)
    {
        int a,b;  scanf("%d%d",&a,&b);
        if(a>=h&&b>=w)
            ans++;
    }
    cout<<ans;
}
