#include <bits/stdc++.h>

#define ll long long
#define ii pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1.0)
#define oo 1000000007
#define loo 10000000000000007

#define prime 1000000007

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, m, mi = prime; cin >> n >> m;
    ll sum = 0;
    for (int i = 0; i < n; ++i){
        ll x; cin >> x;
        mi = min(mi, x);
        sum+=x;
    }

    cout << n + (m-sum)/mi << "\n";
    return 0;
}