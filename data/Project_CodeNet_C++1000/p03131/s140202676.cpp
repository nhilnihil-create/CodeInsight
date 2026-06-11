#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k,a,b,ans=0;
    cin>>k>>a>>b;
    ll diff=b-a;
    if(a+2>=b||k-a<1)
        {cout<<1+k<<endl;return 0;}
    else
    {
        k -= a - 1;
        ll ans = a;
        if(k % 2 == 1)ans++, k--;
        ans += (b - a) * (k / 2);
        cout << ans << endl;
    }
    return 0;
}
