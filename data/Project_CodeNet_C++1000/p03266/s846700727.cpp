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
   ll cnt1=0,cnt2=0;
   ll n,k;cin >>n>>k;
    for (int i = 1; i <= n; ++i) {
        if(k%2==0){
            if(i%k==k/2)cnt1++;
        }
        if(i%k==0)cnt2++;
    }
    ll ans=0;
   ll now=1;
//   cout <<cnt1<<" "<<cnt2<<endl;
    for (int j = 0; j < 3; ++j) {
        now*=cnt1;
    }
    ans+=now;
    now=1;
    for (int l = 0; l < 3; ++l) {
        now*=cnt2;
    }
    ans+=now;
    cout <<ans <<endl;
   return 0;
}