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
    int a,b,x;cin >>a>>b>>x;
    x-=a;
    bool flg=true;
    if(x<0)flg=false;
    if(x>b)flg=false;
    if(flg)puts("YES");
    else puts("NO");
    return 0;
}