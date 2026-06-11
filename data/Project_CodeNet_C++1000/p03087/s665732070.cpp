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
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    vector<int> l(q), r(q);
    rep(i, q) cin >> l[i] >> r[i];
    
    vector<int> A(n);
    rep(i, n - 1) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            A[i + 1] = A[i] + 1;
        }
        else {
            A[i + 1] = A[i];
        }
    }

    rep(i, q) {
        int ans = A[r[i] - 1] - A[l[i] - 1];
        put(ans);
    }

    return 0;
}