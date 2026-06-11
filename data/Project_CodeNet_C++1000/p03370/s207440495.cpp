#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> m[i];
        sum += m[i];
    }
    int ans = n;
    sort(m.begin(), m.end());
    while(sum + m[0] <= x){
        ans++;
        sum += m[0];
    }
    cout << ans << endl;
    return 0;
}
