#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> l,r;
    int zero = 0;
    rep(i,n){
        ll now;
        cin >> now;
        if(now == 0) zero++;
        else if(now > 0) r.push_back(now);
        else if(now < 0) l.push_back(now);
    }
    sort(l.rbegin(),l.rend());
    if(zero >= k){
        cout << 0 << endl;
        return 0;
    }
    k -= zero;
    ll ans = 1e12;
    for(ll L=0; L<=k; L++){
        ll R = k-L;
        if(L<=(int)l.size() && R<=(int)r.size()){
            ll now;
            if(L==0){
                now = r[k-1];
            } 
            else if(R==0){
                now = abs(l[k-1]);
            }
            else{
                now = min(2*abs(l[L-1])+r[R-1],2*r[R-1]+abs(l[L-1]));
            }
            ans = min(ans,now);
        }
    }
    cout << ans << endl;

    return 0;
}
