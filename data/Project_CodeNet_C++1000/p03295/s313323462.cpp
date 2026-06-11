#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<P> vec(m);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        vec[i].first = b;
        vec[i].second = a;
    }
    sort(vec.begin(), vec.end());

    int cur = -1e9;
    int ans = 0;
    rep(i,m){
        if (vec[i].second >= cur){
            cur = vec[i].first;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
