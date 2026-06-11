#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

int r,d,x,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin>>r>>d>>x;
    ans=x;
    rep(i,1,10)
    {
        ans = r*ans-d;
        cout<<ans<<endl;
    }
}
