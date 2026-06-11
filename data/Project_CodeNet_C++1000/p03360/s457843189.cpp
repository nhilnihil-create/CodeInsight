#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll v = max(a, max(b, c));
    rep(i, k) v *= 2;
    put(v + a + b + c - max(a, max(b, c))) 
    return 0;
}