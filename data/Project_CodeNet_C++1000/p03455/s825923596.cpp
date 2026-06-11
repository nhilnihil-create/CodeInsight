#include <bits/stdc++.h>
using namespace std;

struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) (1 + (int)((a) - 1)/(int)(b))
#define int long long

signed main(){
    int a, b;
    cin >> a >> b;
    cout << ((a*b) % 2 == 1 ? "Odd" : "Even") << endl;
}