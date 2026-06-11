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

ll n, m;
string a, b;

vector < pair <char, int> > g[5];

int main(){

mal

cin >> n >> m;
cin >> a >> b;


if(n == 1 || m == 1 || a[0] != b[0]) {cout << -1;return 0;}

if(n < m) {swap(n, m); swap(a, b);}



ll N = (n * m) / __gcd(n, m);


ll val1 = (((N / n * 1ll) * (N / m * 1ll) / __gcd((N / n) * 1ll, (N / m * 1ll)))) / (N / n * 1ll);

for(int i = 0; i < a.sz() - 1; ++i) {

    if((i + 1) % val1 == 0) {g[1].pb(mper(a[i], (i + 1) * (N / n) + 1));}

}

for(int i = 1; i < a.sz(); ++i) {

    if(i % val1 == 0) {g[2].pb(mper(a[i], (i) * (N / n) + 1));}

}

ll val2 = (N / n * 1ll) * (N / m * 1ll) / __gcd((N / n * 1ll), (N / m * 1ll)) / (N / m * 1ll);

for(int i = 0; i < b.sz() - 1; ++i) {

    if((i + 1) % val2 == 0) {g[3].pb(mper(b[i], (i + 1) * (N / m) + 1));}

}

for(int i = 1; i < b.sz(); ++i) {

    if(i % val2 == 0) {g[4].pb(mper(b[i], (i) * (N / m) + 1));}

}

ll cnt1 = 0;
ll cnt2 = 0;
ll cnt3 = 0;
ll cnt4 = 0;

bool check1 = 0;

for(int i = 0; i < g[1].sz(); ++i) {

//        cout << g[1][i].fe << ' ' << g[2][i].fe << ' ' << g[3][i].fe << ' ' << g[4][i].fe << '\n';

        if(g[3].sz() == g[1].sz()) {

            if(g[1][i].fe == g[3][i].fe) {
                cnt1++;

            }

        }

        if(g[4].sz() == g[1].sz()) {

            if(g[1][i].fe == g[4][i].fe && g[1][i].se >= g[4][i].se) {cnt2++;}

        }

        if(g[3].sz() == g[2].sz()) {

            if(g[2][i].fe == g[3][i].fe && g[2][i].se >= g[3][i].se) {cnt3++;}

        }

        if(g[4].sz() == g[2].sz()) {

            if(g[2][i].fe == g[4][i].fe && g[2][i].se >= g[4][i].se) {cnt4++;}

        }

}

ll all = max(max(g[1].sz() * 1ll, g[2].sz() * 1ll), max(g[3].sz() * 1ll, g[4].sz() * 1ll));

if(cnt1 == all || cnt2 == all || cnt3 == all || cnt4 == all) {cout << N;return 0;}
else {cout << -1;}

return 0;
}
