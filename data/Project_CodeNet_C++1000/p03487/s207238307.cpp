#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    unordered_map<int, int> c;
    rep(i, n) c[a[i]] = 0;
    rep(i, n) c[a[i]]++;

    ll sum = 0;
    for (auto kv: c) {
        int ai = kv.first;
        int ci = kv.second;
        if (ai <= ci) sum += ci - ai;
        else sum += ci;
    }

    put(sum);

    return 0;
}