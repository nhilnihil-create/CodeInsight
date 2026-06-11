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
   ll n;cin >>n;
   string s;cin >>s;
   string x,y;
   ll ans=0;
    for (int i = 0; i < n; ++i) {
        x=s.substr(0,i);
        y=s.substr(i,n-i);
        ll now=0;
        map<char,ll>mp;
        for (int j = 0; j < x.size(); ++j) {
            char key=x[j];
            if(mp[key]>0)continue;
            mp[key]++;
            for (int k = 0; k < y.size(); ++k) {
                if(key==y[k]){
                    now++;
                    break;
                }
            }
        }
        ans=max(ans,now);
    }
    cout <<ans <<endl;
   return 0;
}