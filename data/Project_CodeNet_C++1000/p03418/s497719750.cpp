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
    ll ans = 0;
    for(int b = 1; b <= n; b++){
        int p = n/b;
        int r = n%b;
        ans += max(b-k, 0) * p;
        ans += max(r+1-k, 0);
        if(k==0) ans--;
    }
    cout << ans << endl;
}