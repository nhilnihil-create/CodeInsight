#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string s;
    cin >> s;
    int x = 700;
    rep(i, s.size()) {
        if (s[i] == 'o') {
            x += 100;
        }
    }
    cout << x << endl;
    return 0;
}