#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    YORN (a[0] == b[2] && a[1] == b[1] && a[2] == b[0]);
    return 0;
}