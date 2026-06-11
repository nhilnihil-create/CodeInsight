#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    int ans;cin>>ans;
    for(int i=1;i<n;i++)
    {
        int a;cin>>a;
        ans=gcd(ans,a);
    }

    cout<<ans<<"\n";

    return 0;
}
