#include <bits/stdc++.h>
using namespace std;


#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

ll mod = 1e9 + 7ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll inf = 1ll << 60;

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    cout << h*w - a*w - b*h + a*b << endl;
    return 0;
}
