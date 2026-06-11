#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    ll n,m;
    cin >> n >> m;
    multimap<ll,ll> st;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        st.insert(make_pair(a,b));
    }
    ll ans = 0;
    for(auto a : st){
        if(m < a.second){
            ans += m*a.first;
            break;
        }
        else{
            ans += a.second*a.first;
            m -= a.second;
        }
    }
    cout << ans << endl;
    return 0;
}