#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl
using namespace std;
int main()
{
    string n;
    cin >> n;
    int cnt = 0;
    char prev = ' ';
    int maxCnt = 0;
    rep (i, n.size()) {
        if (prev == n[i]) {
            cnt++;
        }
        else {
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
            prev = n[i];
        }
    }
    maxCnt = max(maxCnt, cnt);
    yorn (maxCnt >= 3);
    return 0;
}