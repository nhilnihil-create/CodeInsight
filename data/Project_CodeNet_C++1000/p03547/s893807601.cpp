#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl
using namespace std;
int main()
{
    char x, y;
    cin >> x >> y;
    if (x < y) {
        println("<");
    }
    else if (x == y) {
        println("=");
    }
    else {
        println(">");
    }
    return 0;
}