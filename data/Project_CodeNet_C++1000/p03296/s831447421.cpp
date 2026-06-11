#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz size
#define se second
#define fe first
#define mper make_pair
#define all(x) x.begin(), x.end()
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define saken string
#define erba continue
#define vl vector<ll>
#define vi vector<int>
#define vli vector <pair <ll, int> >
#define vll vector <pair <ll, ll> >
using namespace std;

ll n, a[110];

int main(){

cin >> n;

for(int i = 1; i <= n; ++i) {
    cin >> a[i];
}

ll ct = 1;

ll ans = 0;

for(int i = 2; i <= n; ++i) {

    if(a[i] != a[i - 1]) {ans += ct / 2; ct = 1;}
    else {ct++;}

}

ans += ct / 2;

cout << ans;

return 0;
}

