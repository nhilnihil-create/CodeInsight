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
   ll ans=0;
   vector<ll>t(5);
    for (int i = 0; i < 5; ++i) {
        cin >>t[i];
        ans+=(t[i]/10)*10;
        t[i]%=10;
        if(!t[i])t[i]+=10;
    }
    sort(all(t));
    ans+=t[0]%10;
    for (int i =1; i < 5; ++i) {
        if(t[i]!=10)ans+=10;
    }
    cout <<ans <<endl;
   return 0;
}