#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> money(n+1);
    rep(i,m){
        int a;
        cin >> a;
        money[a]++;
    }
    int ans = 1e5;
    int sum = 0;
    for(int i = x; i <= n; i++) sum += money[i];
    ans = min(ans, sum);
    sum = 0;
    for(int i = 0; i <= x; i++) sum += money[i];
    ans = min(ans, sum);
    cout << ans << endl;
}