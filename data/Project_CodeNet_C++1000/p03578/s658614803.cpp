#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m;
    cin >> n;
    map<int, int> m1, m2;
    
    rep(i, n){
        int d;
        cin >> d;
        m1[d]++;
    }
    cin >> m;

    bool ok = true;
    rep(i, m){
        int t;
        cin >> t;
        m2[t]++;
    }

    for (auto& p : m2) {
        if(m1[p.first] < p.second){
            ok = false;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}