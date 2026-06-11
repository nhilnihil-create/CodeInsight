#include <bits/stdc++.h>
using namespace std;

#define int long long
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
//const int MOD = 10000;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))
int gcd(int x,int y){if(y==0) return x; return gcd(y, x%y);}
int lcm(int x,int y){return x/gcd(x,y)*y;}

pair<intpair, intpair> square_vertex(int x1, int y1, int x2, int y2){
    int X = x2 - x1, Y = y2 - y1;
    return {{x2-Y, y2+X}, {x1-Y, y1+X}};
}

signed main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    auto p = square_vertex(x1, y1, x2, y2);
    cout << p.first.first << " " << p.first.second << " ";
    cout << p.second.first << " " << p.second.second << endl;
}