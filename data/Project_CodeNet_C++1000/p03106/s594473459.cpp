#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b, k;
    cin >> a >> b >> k;

    vector<int> ans;
    for(int i = 1; i <= 100; i++){
        if((a%i == 0) && (b%i == 0)) ans.push_back(i);
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans[k-1] << endl;
    return 0;
}