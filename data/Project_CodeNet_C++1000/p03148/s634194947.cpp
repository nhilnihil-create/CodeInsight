#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    ll N,K;
    cin >> N >> K;
    vector<Pll> p(N);;
    rep(i,N){
        ll t,d;
        cin >> t >> d;
        p[i]=Pll(d,t);
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    ll ans=0,count=0;
    map<ll,ll> m;
    rep(i,K){
        count+=p[i].first;
        m[p[i].second]++;
    }
    ll s=m.size();
    count+=s*s;
    ans=count;
    ll checked=K-1,last=K-1;
    for (int i=checked;i>=0;i--){
        if (m[p[i].second]>1){
            count-=p[i].first;
            m[p[i].second]--;
            bool update=false;
            for (int j=last+1;j<N;j++){
                if (m[p[j].second]==0){
                    count+=p[j].first;
                    m[p[j].second]++;
                    last=j;
                    s++;
                    update=true;
                    break;
                }
            }
            if (update){
                count+=s*2-1;
                ans=max(ans,count);
            }
            else {
                break;
            }
        }
    }
    cout << ans << endl;
}