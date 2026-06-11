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
    vector<int> A(2 * n);
    rep(i, 2 * n) cin >> A[i];

    int mi = 0;
    rep(p, n) {
        int sum = 0;
        for (int i = 0; i <= p; i++) {
            sum += A[i];
        }
        for (int i = p; i < n; i++) {
            sum += A[n + i];
        }
        mi = max(mi, sum);
    }

    put(mi);
    

    return 0;
}