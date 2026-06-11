#include <bits/stdc++.h>
#define int long long
#define x first
#define y second


using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> q(n);
    for(int i = 0; i < n; i++){
        cin >> q[i];
    }
    vector<int> nxt(n);
    int l = n;
    for(int i = n - 1; i >= 0; i--){
        nxt[i] = l;
        if(q[i] != 0){
            l = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        int x = 0;
        for(int j = i; j <n;){
            sum += q[j];
            x = x^q[j];
            if(sum != x){
                ans += j - i;
                break;
            }
            j = nxt[j];
            if(j == n){
                ans += j - i;
            }
        }
    }
    cout << ans;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    //freopen("output.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //cin >> test;
    while(test--){
        solve();
    }
}
