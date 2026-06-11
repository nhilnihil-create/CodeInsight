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
    string ans="keyence";
    string s;cin >>s;
    int n=s.size();
    vector<string>f(8);
    vector<string>b(8);
    for (int i = 0; i < 8; ++i) {
        f[i]=s.substr(0,i);
    }
    for (int i = 0; i < 8; ++i) {
        b[i]=s.substr(n-i,i);
    }
    bool flg=false;
    for (int i = 0; i < 8; ++i) {
        if(f[i]+b[7-i]==ans)flg=true;
//        cout <<f[i]<<" "<<b[7-i]<<endl;
    }
    if(flg)puts("YES");
    else puts("NO");
}
