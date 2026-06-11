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
    ll n;
    cin >> n;
    vector<ll> a(5);
    rep(i, 5) cin >> a[i];
    
    ll mi = *min_element(all(a));
    ll grp = (n + mi - 1) / mi;

    put(4 + grp);    

    return 0;
}