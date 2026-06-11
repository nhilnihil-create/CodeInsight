#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string n;
    cin >> n;
    rep(i, n.size()) {
        cout << (n[i] == '1' ? 9:1);
    }
    cout << endl;
    return 0;
}