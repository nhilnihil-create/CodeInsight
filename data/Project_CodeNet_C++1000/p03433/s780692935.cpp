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
    int n,a;cin >>n>>a;
    for (int i = 0; i <=a; ++i) {
        if((n-i)%500==0)flg=true;
    }
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}