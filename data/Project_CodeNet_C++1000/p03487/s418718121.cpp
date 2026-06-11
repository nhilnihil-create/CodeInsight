#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    map<int, int> m;
    rep(i, N){
        int a; cin >> a;
        m[a]++;
    }

    int ans = 0;
    for (auto p : m){
        auto key = p.first;
        auto value = p.second;
        if(key < value){
            ans += value - key;
        } else if(key > value){
            ans += value;
        } else {
            continue;
        }
    }

    cout << ans << endl;

    return 0;
}