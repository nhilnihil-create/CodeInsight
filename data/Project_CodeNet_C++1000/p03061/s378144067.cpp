#include<bits/stdc++.h>
#define ll long long int
#define pragi(a,b) for(ll i = a;i<b;i++)
#define pragj(a,b) for(ll j = a;j<b;j++)
#define pragk(a,b) for(ll k = a;k>=b;k--)
#define all(v) (v.begin(),v.end())
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define KAKA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long double ld;
typedef pair<int, int> pii;
//typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;

void Compute(ll n)
{
    KAKA
    vector<ll> ar(n);
    pragi(0,n)
    {
        cin>>ar[i];
    }
    vector<ll> prefgcd(n);
    vector<ll> sufgcd(n);
    prefgcd[0] = ar[0];
    sufgcd[n - 1] = ar[n - 1];
    pragi(1,n)
    {
        prefgcd[i] = __gcd(prefgcd[i - 1],ar[i]);
    }
    pragk(n - 2,0)
    {
        sufgcd[k] = __gcd(sufgcd[k + 1],ar[k]);
    }
    vector<ll> vec;
    vec.eb(sufgcd[1]);
    vec.eb(prefgcd[n - 2]);
    pragi(1,n - 1)
    {
        vec.eb(__gcd(prefgcd[i - 1],sufgcd[i + 1]));
    }
    ll mx = *max_element(vec.begin(),vec.end());
    cout<<mx<<"\n";
}
int main()
{
    KAKA
    ll n;
    cin>>n;
    Compute(n);
}