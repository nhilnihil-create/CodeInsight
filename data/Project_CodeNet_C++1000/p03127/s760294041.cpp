#include <bits/stdc++.h> 
#define ll long long int
#define DEBUG(x) cerr<<"> "<< #x << ':' <<x<<endl;
using namespace std;
ll INF = 1e15;
ll MOD = 1e9 + 7;
vector <ll> monster;

ll gcd(ll a, ll b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll input;
        cin>>input;
        monster.push_back(input);
    }
    ll ans = monster[0];
    for(int i=0;i<n;i++)
    {
        ans = gcd(ans, monster[i]);
    }
    cout<<ans<<"\n";
    return 0;
}