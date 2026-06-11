#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {

    int n,m; cin >> n >> m;
    int x[100001];
    ll ans = 0;
    vector<int> d;

    rep(i,m){
        cin >> x[i];
    }

    sort(x,x+m);

    rep(i,m-1){
        d.push_back(x[i+1]-x[i]);
    }

    sort(d.begin(),d.end());
    rep(i,m-1-(n-1)){
        ans += d[i];
    }

    cout << ans;


    return 0;
}









