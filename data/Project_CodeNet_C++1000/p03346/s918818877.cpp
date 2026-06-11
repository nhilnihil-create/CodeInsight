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
ll n, pos[MAXN], ans, pref[MAXN];

void solve() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        ll ai;
        cin >> ai;
        pos[ai] = i;

    }
    
    for(int i = 1; i <= n; ++i) {

        pref[i] += 1;
        if(pos[i] < pos[i + 1]) {pref[i + 1] += pref[i];}
        ans = max(ans, pref[i]);
    }

    cout << n - ans;

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

