#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    int n,k; cin>>n>>k;
    map<int,int> cnt;
    rep(i,0,n){
        int x; cin>>x;
        cnt[x]++;
    }
    vector<int> t;
    for(auto &i: cnt){
        t.push_back(i.second);
    }
    sort(all(t));
    reverse(all(t));
    ll ans=0;
    rep(i,k,t.size()){
        ans+=t[i];
    }
    cout<<ans<<endl;
}