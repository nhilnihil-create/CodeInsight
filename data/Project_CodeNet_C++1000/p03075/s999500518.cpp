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
   bool flg=false;
   vector<ll>d(5);
    for (int i = 0; i < 5; ++i) {
        cin >>d[i];
    }
    ll k;cin >>k;
    if(d[4]-d[0]>k)flg=true;
    if(flg)puts(":(");
    else puts("Yay!");
   return 0;
}