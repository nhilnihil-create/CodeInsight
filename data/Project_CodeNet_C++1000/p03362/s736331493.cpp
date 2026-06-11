#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int n; cin >> n;
    vector<int> ans;
    vector<bool> p(55556,true);
    for(int i=2;i*i<=55555; i++) {
        if(p[i])
        for(int j=i*2;j<=55555;j+=i) {
            p[j] = false;
        }
    }
    int start = 3; int cnt = 0;
    if(n&1) start = 2;
    for(int i=start;i<=55555;i++) {
        if(p[i] && i%5 == 1) {
            ans.push_back(i);
            cnt++;
        }
        if(cnt >= n) break;
    }
    rep(i, n) cout << ans[i] << ((i==n-1)?"\n":" ");
}
