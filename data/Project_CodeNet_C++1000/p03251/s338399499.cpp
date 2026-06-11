#include <algorithm>
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
    vx.push_back(x);
    vy.push_back(y);

    int xmax = *max_element(ALL(vx));
    int ymix = *min_element(ALL(vy));

    if(xmax < ymix){
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }



    return 0;
}
