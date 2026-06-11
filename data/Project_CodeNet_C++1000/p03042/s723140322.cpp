#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    string s;
    cin >> s;
    int a = atoi(s.substr(0, 2).c_str());
    int b = atoi(s.substr(2).c_str());

    if (1 <= a && a <= 12 && (b == 0 || 13 <= b) ){
        put("MMYY");
        return 0;
    }

    if (1 <= b && b <= 12 && (a == 0 || 13 <= a)) {
        put("YYMM");
        return 0;
    }

    if ((a >= 13 || a == 0) && (b >= 13 || b == 0)) {
        put("NA");
        return 0;
    }

    put("AMBIGUOUS")

    return 0;
}