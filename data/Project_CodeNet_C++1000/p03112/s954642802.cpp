#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
using namespace std;
using ll = long long;

int main(){
    ll A,B,Q;
    cin>>A>>B>>Q;
    const ll INF = (ll)2e10;
    vector<ll> s(A+2,INF),t(B+2,INF),x(Q);
    for(ll i=1;i<=A;i++){
        cin>>s[i];
    }
    for(ll i=1;i<=B;i++){
        cin>>t[i];
    }
    s[0] = -INF;
    t[0] = -INF;
    for(ll i=0;i<Q;i++){
        cin>>x[i];
    }
    for(ll i=0;i<Q;i++){
        ll ind_s = lower_bound(s.begin(),s.end(),x[i])-s.begin();
        ll ind_t = lower_bound(t.begin(),t.end(),x[i])-t.begin();
        ll _min = INF;
        ll s1 = x[i]-s[ind_s-1];
        ll s2 = s[ind_s]-x[i];
        ll t1 = x[i]-t[ind_t-1];
        ll t2 = t[ind_t]-x[i];
        // cout<<"s1:"<<s1<<", s2:"<<s2<<", t1:"<<t1<<", t2:"<<t2<<endl;
        _min = min(_min,max(s1,t1));
        _min = min(_min,max(s2,t2));
        _min = min(_min,2*min(s1,t2)+max(s1,t2));
        _min = min(_min,2*min(s2,t1)+max(s2,t1));
        cout<<_min<<"\n";
    }
    
}