#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(105, 0);
    
    for(int i = 0; i < m; i++){
        int v;
        cin >> v;
        a[v] = 1;
    }

    int cost1, cost2;
    cost1 = cost2 = 0;
    for(int i = 0; i < x; i++){
        cost1 += a[i];
    }
    for(int i = x; i < n; i++){
        cost2 += a[i];
    }
    cout << min(cost1, cost2) << endl;

    return 0;
}