#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n,k;
    cin >> n >> k;
    int r = 0;
    vector<int> cnt(n+1);
    rep(i,n){
        int a;
        cin >> a;
        cnt[a]++;
        if(cnt[a] == 1)r++;
    }
    int ans = 0;
    if(r <= k){
        cout << ans << endl;
        return 0;
    }
    r -= k;
    sort(cnt.begin(),cnt.end());
    rep(i,n-k+1){
        ans += cnt[i];
    }
    cout << ans << endl;
}