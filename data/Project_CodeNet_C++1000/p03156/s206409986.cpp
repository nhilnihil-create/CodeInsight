#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, a, b; cin >> n >> a >> b;
    int c = 0, d = 0, e = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x <= a) c++;
        if(a < x && x <= b) d++;
        if(b < x) e++;
    }
    cout << min({c, d, e}) << endl;
    return 0;
}
