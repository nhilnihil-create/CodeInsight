//ssenseeeeeeeeeeeeeeeeeeeeeeeeeeeee
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef unsigned long long ull;
#define MX 1000000000
#define endl '\n'
#define startt ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr first
#define sc second
#define MOD 1000000007

int main()
{
    ll n, m;
    cin >> n >> m;
    ll a[n+1];
    pair<ll, ll> bc[m+1];
    ll bigsum = 0;
    for(ll i = 0 ; i < n; i++)
    {
        cin >> a[i];
        bigsum+=a[i];
    }
    for(ll i = 0; i < m; i++)
    {
        cin >> bc[i].sc;
        cin >> bc[i].fr;
    }
    sort(bc, bc+m);
    sort(a, a+n);
    ll lastpos = 0;
    
    for(ll i = m-1; i >= 0; i--)
    {
        ll sum = 0;
        bool stopped = false;
        ll c = 0;
        for(ll j = lastpos; j < lastpos+bc[i].sc; j++)
        {
            if(a[j] >= bc[i].fr)
            {
                stopped = true;
                break;
            }
            sum+=a[j];
            c++;
        }
        lastpos = lastpos+bc[i].sc;
        bigsum+= c*bc[i].fr-sum;
        if(stopped)
        {
            break;
        }
    }
    cout << bigsum << endl;
}
