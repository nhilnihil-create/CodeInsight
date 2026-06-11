#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   ll N,T;cin >>N>>T;
   vector<P>p;
    for (int i = 0; i < N; ++i) {
        ll t,c;cin>>c>>t;
        if(t<=T)p.push_back({c,t});
    }
    if(p.empty())puts("TLE");
    else {
        sort(all(p));
        cout << p[0].first << endl;
    }
   return 0;
}