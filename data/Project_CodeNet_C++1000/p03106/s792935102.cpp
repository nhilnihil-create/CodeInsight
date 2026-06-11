#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    int c = 0;
    rep(i, min(a, b)) {
        int n = min(a, b) - i;
        if (a % n == 0 && b % n == 0) {
            c++;
            if (c >= k) {
                put(n);
                return 0;
            }
        }
    }
    
    return 0;
}