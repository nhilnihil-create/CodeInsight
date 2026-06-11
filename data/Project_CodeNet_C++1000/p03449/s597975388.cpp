#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    vector<int> up(n,0);
    vector<int> down(n,0);
    vector<int> up_sum(n,0);
    vector<int> down_sum(n,0);
    for(int i = 0; i < n; i++){
        cin >> up[i];
        if(i > 0) up_sum[i] = up_sum[i-1];
        up_sum[i] += up[i];
    }
    for(int i = 0; i < n; i++){
        cin >> down[i];
        if(i > 0) down_sum[i] = down_sum[i-1];
        down_sum[i] += down[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        if(i > 0) tmp = up_sum[i] + down_sum[n-1] - down_sum[i-1];
        else tmp = up_sum[i] + down_sum[n-1];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}