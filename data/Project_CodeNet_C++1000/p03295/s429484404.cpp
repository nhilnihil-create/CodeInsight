#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> vec(m);
    for(ll i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        vec[i]=make_pair(b,a);
    }
    sort(vec.begin(),vec.end());
    ll memo=-1;
    ll res=0;
    for(ll i=0;i<m;i++){
        if(memo>=vec[i].second) continue;
        else if(memo<vec[i].second){
            memo=vec[i].first-1;
            res++;
        }
    }
    cout << res << endl;
}
