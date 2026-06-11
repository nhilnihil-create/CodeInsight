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
   string s;cin >>s;
   ll n=s.size();
   ll ans=0;
   ll mint=INF;
    for (int i = 0; i < n; ++i) {
        ans+=s[i]-'0';
        ans%=1000;
        mint=min(mint,abs(753-ans));
        ans*=10;
    }
    cout <<mint<<endl;
   return 0;
}