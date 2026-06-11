#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int x;
    cin>>x;
    ll ans =1;

    for(int i=2;i<=sqrt(x) ;i++)
    {
        ll temp =i;
        while( temp <= x)
            temp = temp*i;
        temp = temp/i;

        ans = max(ans , temp);
    }
    cout<<ans;
}