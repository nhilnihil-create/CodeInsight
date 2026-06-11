#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n;
    cin >> n;
    vector<ll> a, b, c;
    ll tmp;
    rep(i, n)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    rep(i, n)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    rep(i, n)
    {
        cin >> tmp;
        c.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll cnt = 0;
    rep(j, n)
    {
        auto itr_a = lower_bound(a.begin(),a.end(), b[j]);
        auto itr_c = upper_bound(c.begin(),c.end(), b[j]);
        cnt += (itr_a - a.begin()) * (c.end()-itr_c);
    }
    cout << cnt << endl;
    return 0;
}