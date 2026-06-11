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
    string s;
    cin >> s;

    vector<int> e(n);
    e[0] = s[0] == 'E' ? 1 : 0; 
    repi(i, n) {
        e[i] = e[i-1] + (s[i] == 'E' ? 1 : 0);
    }

    int res = 1e8;
    rep(i, n) {
        int num = e[n-1] - e[i];
        num += i - 1 >= 0 ? i - e[i - 1] : 0;
        res = min(num, res);
     //   put(num)
    }
    put(res);
    return 0;
}