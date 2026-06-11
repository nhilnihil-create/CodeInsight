#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int r;
    cin >> r;
    if (r < 1200) {
        println("ABC");
    }
    else if (r < 2800) {
        println("ARC");
    }
    else {
        println("AGC")
    }
    return 0;
}