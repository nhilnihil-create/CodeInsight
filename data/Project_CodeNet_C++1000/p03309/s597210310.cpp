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

    vector<ll> A(n);
    rep(i, n) A[i] = a[i] - (i + 1);
    sort(all(A));
    
    vector<ll> mid;
    if (A.size() % 2 == 1) {
        mid.push_back(A[A.size() / 2]);
    }
    else  {
        mid.push_back((A[A.size() / 2] + A[A.size() / 2 - 1]) / 2 - 1);
        mid.push_back((A[A.size() / 2] + A[A.size() / 2 - 1]) / 2);
        mid.push_back((A[A.size() / 2] + A[A.size() / 2 - 1]) / 2 + 1);
    }

    ll mi = 1e18;
    rep (j, mid.size()) {
        ll score = 0;
        rep(i, n) score += abs(A[i] - mid[j]);
        mi = min(mi, score);
    }


    put(mi);

    return 0;
}