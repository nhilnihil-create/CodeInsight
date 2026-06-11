// lower_bound
// upper_bound を使う
// 中段を固定して考える方法
//  main.cpp
//  ABC077C
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(int argc, const char * argv[]) {
    ll n;
    cin>>n;
    vector<ll>S(n),M(n),L(n);
    for(ll i=0;i<n;i++){
        cin>>S.at(i);
    }
    for(ll i=0;i<n;i++){
        cin>>M.at(i);
    }
    for(ll i=0;i<n;i++){
        cin>>L.at(i);
    }
    sort(S.begin(),S.end());
    sort(M.begin(), M.end());
    sort(L.begin(), L.end());
    ll ans=0;
    for(ll i=0;i<M.size();i++){
        ll now=M.at(i);
        ll ss=lower_bound(S.begin(), S.end(), now)-S.begin();
        ll ls=L.end()-upper_bound(L.begin(), L.end(), now);
        ans+=ss*ls;
    }
    cout<<ans<<endl;
    return 0;
}
