#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
int inf=100000000;
ll INF=100000000000000000;
ll MOD=1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(),a.end());
    ll k=a.at(n-1);
    ll ans=-1;
    int w;
    rep(i,n){
        ll u=min(a.at(i),k-a.at(i));
        if (ans<u) {ans=u;w=a.at(i);}
    }
    cout << k << " " << w << endl;
}
