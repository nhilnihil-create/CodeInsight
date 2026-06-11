#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main(){
   int n,k;cin>>n>>k;
   vector<ll>v(n);
    for (int i = 0; i < n; ++i) {
        cin >>v[i];
    }
    ll ans=-INF;
    for (int l = 0; l <=min(k, n); ++l) {
        for (int r = 0; r <=min(k,n)-l; ++r) {
            ll no=k-(l+r);
            ll now=0;
            vector<int>m;
            for (int i = 0; i <l; ++i) {
                now+=v[i];
                if(v[i]<0)m.push_back(v[i]);
            }
            for (int j = 0; j <r; ++j) {
                now+=v[n-1-j];
                if(v[n-1-j]<0)m.push_back(v[n-1-j]);
            }
            if(m.size()) {
                sort(all(m));
            }
            for (int i = 0; i < min(no,(ll)m.size()); ++i) {
                now-=m[i];
            }
            ans=max(ans,now);
//            cout <<l<<" "<<r<<" "<<now<<endl;
        }
    }
    cout <<ans <<endl;
}
