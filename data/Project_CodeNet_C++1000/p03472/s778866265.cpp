#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n,h;cin >>n>>h;
    vector<ll>a(n);
    vector<ll>b(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i]>>b[i];
    }
    sort(all(a));
    sort(all(b));
    reverse(all(a));
    reverse(all(b));
    ll ans=0;
    for (int j = 0; j < n; ++j) {
        if(b[j]>=a[0]){
            h-=b[j];
            ans++;
            if(h<=0){
                cout <<ans<<endl;
                return 0;
            }
        }
    }
    ans+=(h-1)/a[0]+1;
    cout <<ans <<endl;
    return 0;
}
