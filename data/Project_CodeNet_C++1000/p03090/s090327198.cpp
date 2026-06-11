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

const ll MAXN = 111;

bool used[MAXN];
ll n;
vector < pair <ll, ll> > ans;

void solve() {

    cin >> n;

    if(n % 2 != 0) {

        for(int i = 1; i <= n / 2; ++i) {

            ll k = n - 1;

            ll l = i;
            ll r = k - i + 1;

            ans.pb(mper(l, n));
            ans.pb(mper(r, n));

        }

        n--;


    }


        for(int i = 1; i <= n / 2; ++i) {

            ll l = i;
            ll r = n - i + 1;
            used[r] = 1;

            for(int j = l + 1; j <= n; ++j) {

                if(!used[j]) {

                    ans.pb(mper(j, l));
                    ans.pb(mper(j, r));

                }

            }

        }

    cout << ans.sz() << '\n';

    sort(all(ans));

    for(auto to : ans) {

        cout << to.fe << ' ' << to.se << '\n';

    }

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

