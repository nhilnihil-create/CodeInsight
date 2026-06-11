#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n,p;
    cin>>n>>p;
    int ans=1;
    for(int i=2;i<=1000000;++i){
        if(p%i==0){
            int cp=0;
            while(p%i==0){
                p/=i;
                cp++;
            }
            cp/=n;
            for(int j=0;j<cp;++j)
            ans*=i;
        }
    }
    if(n==1)
    ans*=p;
    cout<<ans;
    return 0;
}
