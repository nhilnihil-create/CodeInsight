#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define set_bits(a) __builtin_popcount(a)
#define pb push_back
#define pf push_front
#define mod 1000000007
#define M 998244353
#define fi first
#define se second
#define endl '\n'
#define INF 1e18
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll x = a+b;
    ll y = c+d;
    if(x>y)
    {
        cout<<"Left";
    }
    else if(x<y)
    {
        cout<<"Right";
    }
    else
    {
        cout<<"Balanced";
    }
}

