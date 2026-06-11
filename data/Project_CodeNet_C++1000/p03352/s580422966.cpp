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
    ll x;cin >>x;
    vector<bool>ch(x+1,false);
    ch[1]=true;
    for (int i = 2; i <=x; ++i) {
        ll c=i;
        ll now=i;
        now*=c;
        while(now<=x){
            ch[now]=true;
            now*=c;
        }
    }
    for (int i = 0; i < x + 1; ++i) {
        if(ch[x-i]){
            cout <<x-i<<endl;
            return 0;
        }
    }
    return 0;
}