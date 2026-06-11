#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n; cin >> n;
    map<int, int> g;
    map<int, int> k;
    rep(i, n){
        int v; cin >> v;
        if(i%2 == 0){
            g[v]++;
        } else {
            k[v]++;
        }
    }

    int gn;
    int kn; 
    int gcnt = 0;
    int gcnt2 = 0;
    int kcnt = 0;
    int kcnt2 = 0;

    for (auto p : g){
        auto key = p.first;
        auto value = p.second;
        if(gcnt < value){
            gcnt2 = gcnt;
            gcnt = value;
            gn = key;
        } else {
            gcnt2 = max(gcnt2, value);
        }
    }

    for (auto p : k){
        auto key = p.first;
        auto value = p.second;
        if(kcnt < value){
            kcnt2 = kcnt;
            kcnt = value;
            kn = key;
        } else {
            kcnt2 = max(kcnt2, value);
        }
    }
    
    if(gn != kn){
        cout << n-gcnt-kcnt << endl;
    } else {
        int ans = min(n-gcnt-kcnt2, n-gcnt2-kcnt);
        cout << ans << endl;
    }

    return 0;
}