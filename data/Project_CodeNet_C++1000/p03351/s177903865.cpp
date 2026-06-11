#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    yorn(abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d ))

    return 0;
}