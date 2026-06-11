#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k; cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    sort(ALL(h));
    int ans = 1001001001;
    for(int i = 0; i < n-k+1; i++){
        ans = min(ans, h[i+k-1] - h[i]);
    }
    cout << ans << endl;
}