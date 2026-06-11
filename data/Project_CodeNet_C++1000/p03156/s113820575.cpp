#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    int n, a, b; cin >> n >> a >> b;
    vector<int> p(n); rep(i, n) cin >> p[i];
    int x, y, z; x = y = z = 0;
    rep(i, n) {
        if(p[i]<=a) x++;
        else if(p[i]<=b) y++;
        else z++;
    }
    cout << min(x, min(y, z));
}

