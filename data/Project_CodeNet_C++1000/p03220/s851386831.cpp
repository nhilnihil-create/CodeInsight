#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    int t, a;
    cin >> t >> a;
    double near_t = INF;
    int near_p;
    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        double temp;
        temp = t - h * 0.006;
        if(near_t > abs(temp - a)){
            near_t = abs(temp - a);
            near_p = i;
        }
    }
    cout << near_p + 1 << endl;
    return 0;
}