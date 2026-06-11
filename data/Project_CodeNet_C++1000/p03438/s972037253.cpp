#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define all(x) (x).begin(), (x).end()
#define v(T) vector<T>
#define vv(T) vector<v(T)>
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;


int main()
{
    int n;
    cin >> n;
    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll cnt = 0, t = 0;
    rep(i, n) cnt += b[i]-a[i];
    if (cnt < 0) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, n){
        if (a[i] >= b[i]) t += b[i]-a[i];
        else t += (b[i]-a[i])/2;
    }
    if (t >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
