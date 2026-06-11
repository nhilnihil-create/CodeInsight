#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;

    double ans = 0;
    for(int i = 0; i < n; i++){
        double x;
        string u;
        cin >> x >> u;
        if(u == "JPY") ans += x;
        else ans += 380000.0 * x;
    }
    printf("%.5lf", ans);
    return 0;
}