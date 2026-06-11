#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int d;
    cin >> d;
    switch (d)
    {
        case 25:
            println("Christmas");
            break;
        case 24:
            println("Christmas Eve");
            break;
        case 23:
            println("Christmas Eve Eve");
            break;
        case 22:
            println("Christmas Eve Eve Eve");
            break;
    
    default:
        break;
    }
    return 0;
}