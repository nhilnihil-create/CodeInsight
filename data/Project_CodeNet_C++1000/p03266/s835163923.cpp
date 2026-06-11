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
    vector<ll> num(k, 0);
    for(int a = 1; a <= n; a++) num[a%k]++;
    ll ans = 0;
    for(int a = 0; a < k; a++){
        int b = (k - a) % k;
        int c = (k - a) % k;//a=0の時のため
        if((b+c) % k != 0)continue;
        ans += num[a]*num[b]*num[c];
    }
    cout << ans << endl;
}