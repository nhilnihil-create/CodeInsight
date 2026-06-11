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
    ll a,b,c,d;cin >>a>>b>>c>>d;
    bool flg=false;
    if(abs(a-c)<=d)flg=true;
    if(abs(b-a)<=d&&abs(c-b)<=d)flg=true;
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}