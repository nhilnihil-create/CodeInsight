#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=100000000000000000;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    ll ans=0,q=INF;
    rep(i,n){
        cin >> a.at(i) >> b.at(i);
        if (a.at(i)>b.at(i)) q=min(q,b.at(i));
        ans+=a.at(i);
    }
    if (q==INF) q=ans;
    cout << ans-q << endl;
}
