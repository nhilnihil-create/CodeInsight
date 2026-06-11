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
    int d, n;
    cin >> d >> n;
    int x = d == 0 ? 1 : d == 1 ? 100 : 10000;

    int cnt = 0;
    for (int i = 1; ; i++) {
        if (i % 100 == 0) {
            continue;
        }
        cnt ++;
        if (cnt == n) {
            put(x * i);
            return 0;
        }
    }
    return 0;
}