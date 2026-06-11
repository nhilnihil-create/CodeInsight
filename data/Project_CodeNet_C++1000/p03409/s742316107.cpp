#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1001001001;
const ll mod = 1000000007;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> blue(n), red(n);
    vector<bool> used(n, false);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        red[i] = {b, a};
    }
    for(int i = 0; i < n; i++){
        int c, d; cin >> c >> d;
        blue[i] = {c, d};
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        int b_x = blue[i].first, b_y = blue[i].second;
        for(int j = n - 1; j >= 0; j--){
            int r_x = red[j].second, r_y = red[j].first;
            if(used[j]) continue;
            if(r_x >= b_x) continue;
            if(r_y < b_y){
                ans++;
                used[j] = true;
                break;
            }
        }
    }
    cout << ans << endl;
    
}