#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    long long int ans = LLONG_MAX;
    while(t--)
    {
        int a;
        cin>>a;
        long long int count=0;
        while(a%2==0)
        {
            count++;
            a/=2;
        }
        ans = min(ans,count);
    }    
    cout<<ans<<"\n";
}