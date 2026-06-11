#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4 ;
    int d1, d2;
    d1 = x2 - x1;
    d2 = y2 - y1;

    x4 = x1-d2;
    y4 = y1+d1;

    x3 = x1+(d1-d2);
    y3 = y1+(d2+d1);

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;


}