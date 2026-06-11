#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
    int n;
    cin >> n;
    ll a[100002], b[100002];
    P p[100002];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        p[i] = P(a[i] + b[i], a[i]);
    }
    sort(p, p + n, greater<P>());
    ll t = 0, s = 0;
    for(int i = 0; i < n; i++){
        if(i % 2) s += p[i].first - p[i].second;
        else t += p[i].second;
    }
    cout << t - s << endl;
}