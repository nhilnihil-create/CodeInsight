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
    string s;
    cin >> s;

    int n1 = 0;
    rep(i, s.size()) {
        int c = i % 2 == 0 ? '0' : '1';
        if (s[i] != c) n1++;
    }
    int n2 = 0;
    rep(i, s.size()) {
        int c = i % 2 == 0 ? '1' : '0';
        if (s[i] != c) n2++;
    }

    put(min(n1, n2));

    return 0;
}