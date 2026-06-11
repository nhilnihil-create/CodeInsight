#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin>>n;
    ll a[n],b[n];
    vector<pair<ll,int>> c;
    rep(i,n){
        cin>>a[i]>>b[i];
        c.push_back({a[i]+b[i],i});
    }
    
    sort(all(c));
    reverse(all(c));

    ll suma=0,sumb=0;
    rep(i,n){
        int x=c[i].second;
        if(i%2==0) suma+=a[x];
        else sumb+=b[x];
    }
    
    cout<<suma-sumb<<endl;
}

