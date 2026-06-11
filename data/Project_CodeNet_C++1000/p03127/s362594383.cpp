#include <bits/stdc++.h>
#define fio     ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define pi      3.14159265
#define ll      long long
#define repe    ll tc,cas=0;cin>>tc;while(tc--)
#define op      freopen("output.txt", "w", stdout);
using namespace std;


int main()
{
    fio;
    int n,a,ans=0;
    cin>>n;

    while(n--)
    {
        cin>>a;
        if(a==0) ans=a;
        else ans=__gcd(a,ans);
    }
    cout<<ans<<endl;
    return 0;
}
