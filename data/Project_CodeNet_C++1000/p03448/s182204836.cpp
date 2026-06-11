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
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int cnt = 0;
    rep(i, a+1) rep(j, b+1) {
        int remain = x - 500 * i - 100 * j;
        int k = remain / 50;
        if (remain % 50 == 0 && 0 <= k && k <= c) {
            cnt++;
        }
    }
    put(cnt)
    return 0;
}