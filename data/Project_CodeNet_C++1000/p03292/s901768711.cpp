#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define int long long

signed main(){
    int a, b, c;
    cin >> a >> b >> c;
    int x = abs(a-b), y = abs(b-c), z = abs(c-a);
    cout << x + y + z - max({x,y,z}) << endl;
}