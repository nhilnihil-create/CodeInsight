#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz size
#define se second
#define fe first
#define mper make_pair
#define all(x) x.begin(), x.end()
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define vl vector<ll>
#define vi vector<int>
#define vli vector <pair <ll, int> >
#define vll vector <pair <ll, ll> >
#define vii vector <pair <int, int> >
using namespace std;

const ll MAXN = 2e5 + 100;
ll n, a[MAXN];

map <ll, int> mp;

int main(){

cin >> n;

ll ai;

for(int i = 1; i <= n; ++i) {

    cin >> a[i];
    mp[a[i]]++;

}

vector < pair <ll, ll> > g;

ll to = 2147483648ll;
to *= 2ll;

ll ans = 0;

for(int st = 1; st <= 31; ++st) {

    to /= 2ll;

    for(int i = 1; i <= n; ++i) {

        g.pb(mper(a[i], to - a[i]));

    }

}

for(auto key : g) {

    ll l = key.fe;
    ll r = key.se;
    ll to = r + l;

    if(r < 0 || l < 0) {continue;}

    if(r != l && mp[l] && mp[r]) {

            mp[l]--;
            mp[r]--;
            ans++;

    }

    else if(r == l && mp[l] - 2 >= 0) {

        mp[l] -= 2;
        ans++;

    }

}

cout << ans;

return 0;
}
