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
    ll ans=700;
    for (int i = 0; i < 3; ++i) {
        if(s[i]=='o')ans+=100;
    }
    cout <<ans <<endl;
    return 0;
}