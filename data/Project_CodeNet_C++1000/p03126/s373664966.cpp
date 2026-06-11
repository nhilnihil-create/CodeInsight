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
    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    rep(i, m) v[i] = 0;

    rep(i, n) {
        int k;
        cin >> k;
        vector<int> a(k);
        rep(j, k) cin >> a[j];
        rep(j, k) {
            v[a[j]-1] ++;
        }
    }

    int cnt = 0;
    rep(j, m) {
        if (v[j] == n) {
cnt ++;
        }
    }
    put(cnt)


    return 0;
}