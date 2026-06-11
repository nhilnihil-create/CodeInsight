#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n,m; cin >> n;
    map<int,int> mp1, mp2;

    rep(i,n){
        int d; cin >> d;
        mp1[d]++;
    }

    cin >> m;
    vector<ll> t(m);
    rep(i,m){
        cin >> t[i];
        mp2[t[i]]++;
    }

    bool ans = true;
    rep(i,m){
        if(mp2[t[i]] > mp1[t[i]]) ans = false;
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

