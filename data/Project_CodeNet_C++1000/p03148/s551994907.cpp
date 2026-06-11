#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll,ll>
#define PP pair<P,P>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    vector<P> sushi;
    rep(i,n){
        ll d,t; cin >> t >> d;
        sushi.push_back(P(d,t));
    }
    sort(all(sushi));
    reverse(all(sushi));

    priority_queue<ll, vector<ll>, greater<ll> > p;
    vector<bool> check(n+1,true);
    ll ans=0;
    ll kind=0;
    ll oishi,neta;

    rep(i,k){
        oishi=sushi[i].first;
        neta=sushi[i].second;
        ans+=oishi;
        if(check[neta]==false){
            p.push(oishi);
            continue;
        }
        kind++;
        check[neta]=false;
    }

    ans+=kind*kind;
    //cout << ans << endl;
    ll tans=ans;
    for(int i=k; i<n; i++){
        oishi=sushi[i].first;
        neta=sushi[i].second;
        if(p.empty()) continue;
        if(check[neta]==false) continue;
        ll mi=p.top();
        ans-=mi;
        ans+=oishi+2*kind+1;
        kind++;
        p.pop();
        check[neta]=false;
        tans=max(ans,tans);
    }
    cout << tans << endl;
return 0;
}
