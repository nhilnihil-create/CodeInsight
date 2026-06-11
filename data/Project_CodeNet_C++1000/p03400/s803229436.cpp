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
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int sum = x;
    rep(i, n) {
        sum += (d - 1) / a[i] + 1;
    }
    put(sum)
    
    return 0;
}