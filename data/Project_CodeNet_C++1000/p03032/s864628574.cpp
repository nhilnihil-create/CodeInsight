#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    int ans = 0;

    for(int i = 0; i < n; i++) cin >> v[i];

    for(int left = 0; left <= k; left++){
        for(int right = 0; right <= k; right++){
            if(right+left > min(n,k)) continue;
            int m = k-left-right;
            int can = 0;
            priority_queue<int,vector<int>,greater<int>> que;
            for(int i = 0; i < left; i++){
                que.push(v[i]);
                can += v[i];
            }
            for(int i = n-right; i < n; i++){
                que.push(v[i]);
                can += v[i];
            }
            for(int i = 0; i < m; i++){
                if(que.empty() || que.top() > 0) break;
                can -= que.top(); que.pop();
            }
            if(ans < can) ans = can;
        }
    }
    cout << ans << endl;
    return 0;
}
