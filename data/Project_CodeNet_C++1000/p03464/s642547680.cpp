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

const ll INF = 1e15;

const ll MAXN = 1e5 + 100;
ll n, a[MAXN];

int check(ll val) {

    for(int i = 1; i <= n; ++i) {

        val -= (val % a[i]);

    }

    if(val == 2) {return 0;}
    else if(val > 2) {return 1;}
    else {return 2;}

}

void bin_search() {


    ll l = 2;
    ll r = INF;
    ll mx = -1;
    ll mn = INF;

    while(l <= r) {

        ll mid = (l + r) / 2ll;

        if(check(mid) == 0) {r = mid - 1; mx = max(mx, mid); mn = min(mn, mid);}
        else if (check(mid) == 1) {r = mid - 1;}
        else {l = mid + 1;}

    }

    l = 2;
    r = INF;

    while(l <= r) {

        ll mid = (l + r) / 2ll;

        if(check(mid) == 0) {l = mid + 1; mx = max(mx, mid); mn = min(mn, mid);}
        else if (check(mid) == 1) {r = mid - 1;}
        else {l = mid + 1;}

    }

    if(mn == INF && mx == -1) {cout << -1;return;}

    cout << mn << ' ' << mx;


}

void solve() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {

        cin >> a[i];

    }

    bin_search();

}

int main(){

mal
//freopen("ladder.in", "r", stdin);
//freopen("ladder.out", "w", stdout);

ll tt = 1;


while(tt--) {

    solve();

}

return 0;
}

