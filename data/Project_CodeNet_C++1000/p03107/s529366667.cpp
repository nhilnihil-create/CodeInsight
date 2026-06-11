#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
   vector<ll>d;
   ll key=0;
   string s;cin >>s;
   ll n=s.size();
   ll now=0;
    for (int i = 0; i < n; ++i) {
        if(s[i]-'0'==key){
            now++;
        }
        else {
            d.push_back(now);
            key=1-key;
            now=1;
        }
    }
    d.push_back(now);
    if(d.size()%2==1)d.push_back(0);
    ll l=0,r=0;
    ll ans=0;
//    for (int j = 0; j < d.size(); ++j) {
//        cout <<d[j]<<" ";
//    }
//    cout <<endl;
    for (int i = 0; i <d.size(); i+=2) {
        l+=d[i];
        r+=d[i+1];
        ll mint=min(l,r);
        ans+=mint*2;
        l-=mint;
        r-=mint;
    }
    cout <<ans <<endl;
}

