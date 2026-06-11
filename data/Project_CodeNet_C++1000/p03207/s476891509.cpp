#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n){
        cin >> p.at(i);
    }
    sort(p.begin(),p.end());
    p.at(n-1) /= 2;
    int64_t ans = 0;
    rep(i,n){
        ans += p.at(i);
    }
    cout << ans << endl;
}