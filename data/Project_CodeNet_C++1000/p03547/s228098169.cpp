#include <bits/stdc++.h>
using namespace std;

struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))
#define int long long

signed main(){
    char x, y;
    cin >> x >> y;
    if(x == y){
        cout << '=' << endl;
    }else{
        cout << (x > y ? '>' : '<') << endl;
    }
}