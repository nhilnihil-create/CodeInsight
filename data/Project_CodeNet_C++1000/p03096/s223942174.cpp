#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
ll MOD=1000000007;
int inf=1000000000;
ll INF=10000000000000000;
int main(){
    int n;
    cin >> n;
    vector<int> a(0);
    int t;
    cin >> t;
    a.push_back(t);
    rep(i,n-1){
        cin >> t;
        if (t==a.at(a.size()-1)) continue;
        a.push_back(t);
    }
    ll ans=1;
    map<int,ll> m;
    rep(i,a.size()){
        int k=a.at(i);
        auto it=m.find(k);
        if (it==m.end()) m[k]=ans;
        else {
            ll u=m[k];
            m[k]=(m[k]+ans)%MOD;
            ans=(ans+u)%MOD;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}