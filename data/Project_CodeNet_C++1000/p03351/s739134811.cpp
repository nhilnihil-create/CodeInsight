#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define rreps(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) (1 + (int)((a) - 1)/(int)(b))
//#define int long long

signed main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool can = abs(a-c) <= d || (abs(a-b) <= d && abs(b-c) <= d);
    cout << (can ? "Yes" : "No") << endl;
}