// 2019-11-01-18.57.19
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    ios::sync_with_stdio (false), cin.tie (0);
    int n;
    cin >> n;
    vi a(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(a[i] , mx);
    }
    sort(a.begin(), a.end());
    pair < int , int > ans = {1e9 , -1};
    for(int i = 0; i < n; i++){
            int x = abs(a[i] * 2 -  a[n - 1]);
        ans = min(ans , make_pair(x , a[i]));
    }
    cout<< a[n - 1] << ' ' << ans.second << '\n';
    return 0;
}











