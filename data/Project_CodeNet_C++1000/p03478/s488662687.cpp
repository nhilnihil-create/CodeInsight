#include <bits/stdc++.h>
#define ll long long int
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
    int n, a, b;
    cin >> n >> a >> b;
    int cnt = 0;
    repi(i, n+1) {
        int v = 0;
        int t = i;
        while (t > 0) {
            v += t % 10;
            t /= 10;
        }
        if (a <= v && v <= b) {
            cnt += i;
        }
    }
    put(cnt)
    return 0;
}