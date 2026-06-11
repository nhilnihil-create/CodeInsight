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

const ll MAXN = 1e5 + 100;
ll n, m;
string a, b;

map < ll, char> mp;

string nans1, nans2, mans1, mans2;

int gcd(int a, int b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long a, long b){
    return a / gcd(a, b) * b;
}

int main(){

mal

cin >> n >> m;
cin >> a >> b;


if(n == 1 || m == 1 || a[0] != b[0]) {cout << -1;return 0;}

ll l = lcm(n, m);

for(int i = 1; i < n; ++i) {

    mp[i * (l / n) + 1] = 1;

}

for(int i = 1; i < m; ++i) {

    ll k = i * (l / m) + 1;

    if(mp[k]) {

        if(a[(k - 1) / (l / n)] != b[i]) {cout << -1;return 0;}

    }

}

cout << l;

return 0;
}
