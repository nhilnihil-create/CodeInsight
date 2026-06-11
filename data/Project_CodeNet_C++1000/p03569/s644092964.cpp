#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second


int main(){
    string s;
    cin >> s;
    string t = "";
    rep(i,0,s.size()) if(s[i] != 'x') t += s[i];

    rep(i,0,t.size()/2){
        if(t[i] != t[t.size()-i-1]){
            cout << -1 << endl;
            return 0;
        }
    }

    ll cnt1[t.size()/2+1] = {},cnt2[t.size()/2+1] = {};
    ll memo = 0;
    rep(i,0,s.size()){
        if(s[i] == 'x'){
            cnt1[memo]++;
        }
        else{
            memo++;
        }
        if(memo >= t.size()/2+1) break;
    }

    memo = 0;
    rep(k,0,s.size()){
        ll i = s.size()-k-1;
        if(s[i] == 'x'){
            cnt2[memo]++;
        }
        else{
            memo++;
        }
        if(memo >= t.size()/2+1) break;
    }

    ll ans = 0;
    rep(i,0,t.size()/2+1){
        ans += abs(cnt1[i] - cnt2[i]);
    }
    cout << ans << endl;

    return 0;
}
