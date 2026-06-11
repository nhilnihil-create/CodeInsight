#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int v = -150, w = MOD;

    rep(i, n){
        int tmp;
        cin >> tmp;
        v = max(v, tmp);
    }
    rep(i, m){
        int tmp;
        cin >> tmp;
        w = min(w, tmp);
    }
    v++;

    for (int i = v; i <= w; ++i) {
        if(x < i && i <= y){
            cout << "No War" << endl;
            return 0;
        }
    }

    cout << "War" << endl;

    return 0;
}
