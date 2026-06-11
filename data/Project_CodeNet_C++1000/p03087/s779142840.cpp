#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll signed long long int

ll c[MAXX], o;
multiset<ll> ms;
multiset<ll>::iterator it;
signed main()
{
    FAST;
    string s;
    ll t;
    ll n;
    cin >> n >> t;
    cin >> s;
    ll ans, h = 0;
    for(int i = 1; i < n; i++){
        c[i + 1] = c[i];
        if(s[i - 1] == 'A' && s[i] == 'C')
            c[i + 1]++;
    }
    while(t--){
    	ll a, b;
        cin >> a >> b;
        cout << (c[b] - c[a]) << endl;
    }
}