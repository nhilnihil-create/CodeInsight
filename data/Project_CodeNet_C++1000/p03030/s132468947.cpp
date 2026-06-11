//
// author  : Abhishek
//
#include <bits/stdc++.h>

#define ll long long
#define db double
#define deb(x) cout<<#x<<": "<<x<<"\n"
#define all(x) x.begin(),x.end()
#define fo(i, n) for(i=0 ; i<n ; i++)
#define Fo(i, k, n) for(i=k ; i<n ; i++)

using namespace std;

const ll mod = 1000000007;
const ll N = 200005;  // array size
const ll inf = 10000000000000000;


void print(vector<ll> v) {
    ll i;
    fo(i, v.size())cout << v[i] << " ";
    cout << "\n";
}

vector<ll> read(ll n) {
    ll i;
    vector<ll> arr(n, 0);
    fo(i, n)cin >> arr[i];
    return arr;
}

vector<ll> read(ll n, ll k) {
    ll i;
    vector<ll> arr(n + k, 0);
    Fo(i, k, n + k)cin >> arr[i];
    return arr;
}

bool isEven(ll n) {
    return n % 2 == 0;
}

bool isOdd(ll n) {
    return n % 2 == 1;
}


void solve() {
    ll t;
    cin >> (t);
    while (t--) {

        ll i, j, k, n, m, p, q, x, y, a, b, l, r;


    }
}


bool cmp(pair<string, pair<ll, ll> > p1, pair<string, pair<ll, ll> > p2) {
    if (p1.first != p2.first) {
        return (p1.first < p2.first);
    }

    return (p1.second.first > p2.second.first);
}

int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll i, j, k, n, m, p, q, x, y, a, b, l, r;


    vector<pair<string, pair<ll, ll> > > arr;
    cin >> n;
    fo(i, n) {
        string str;
        cin >> str;
        cin >> x;
        arr.push_back({str, {x, i + 1}});
    }

    sort(all(arr), cmp);

    fo(i,n){
        cout<<arr[i].second.second<<"\n";
    }

    return 0;
}


