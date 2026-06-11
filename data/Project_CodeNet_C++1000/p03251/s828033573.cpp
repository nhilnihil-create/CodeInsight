#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    V<int> vx(n);
    for(int i = 0; i < n; i++) cin >> vx[i];
    V<int> vy(m);
    for(int i = 0; i < m; i++) cin >> vy[i];
    sort(ALL(vx));
    sort(ALL(vy));
    if(x < vx[n - 1] && vy[0] <= y && vx[n - 1] < vy[0]){
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }



    return 0;
}
