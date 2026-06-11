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
    s += " ";
    
    vector<ll> vec;
    rep(i,0,s.size()-1){
        if(s[i] == 'A') vec.push_back(2);
        else if(s[i] == 'B' && s[i+1] == 'C'){
            vec.push_back(1);
            i++;
        }
        else{
            vec.push_back(0);
        }
    }

    ll cnt = 0,ans = 0;
    rep(k,0,vec.size()){
        ll i = vec.size()-k-1;
        if(vec[i] == 1) cnt++;
        else if(vec[i] == 2) ans += cnt;
        else cnt = 0;
    }

    cout << ans << endl;
    return 0;
}
