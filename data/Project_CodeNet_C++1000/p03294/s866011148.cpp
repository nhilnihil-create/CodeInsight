#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100010];
    long long ans = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    ans -= n;
    cout<<ans<<endl;
    return 0;
}