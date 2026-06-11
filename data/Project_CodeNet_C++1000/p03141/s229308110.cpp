#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

static const int MAX = 1e6;
static const int NIL = -1;
static const ll INF = 1<<21;
static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

int main(void) {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    ll ans = 0;
    for(int i=0;i<n;i++) {
        cin >> a.at(i) >> b.at(i);
        c.at(i) = a.at(i) + b.at(i);
        ans -= b.at(i);
    }

    sort(c.begin(), c.end(), greater<ll>());

    int num = n / 2;
    if(n%2==1) num++;

    for(int i=0;i<2*num-1;i+=2) {
        ans += c.at(i);
    }

    cout << ans << endl;

    return 0;
}
