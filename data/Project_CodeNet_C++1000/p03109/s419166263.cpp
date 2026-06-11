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
    int m = atoi(s.substr(5, 2).c_str());
    int d = atoi(s.substr(8, 2).c_str());
    bool before = false;
    if (m < 4) {
        before = true;
    }
    else if (m == 4 && d <= 30) {
        before = true;
    }
    if (before) {
        println("Heisei");
    }
    else {
        println("TBD");
    }
    return 0;
}