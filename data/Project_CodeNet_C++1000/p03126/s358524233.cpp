#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> food(m, 0);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int a;
            cin >> a;
            a--;
            food[a]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(food[i] == n) ans++; 
    }
    cout << ans << endl;
    return 0;
}