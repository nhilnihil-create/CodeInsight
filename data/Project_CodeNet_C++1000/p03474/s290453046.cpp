#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    int a,b;cin >>a>>b;
    string s;cin >>s;
    bool flg=true;
    for (int i = 0; i < a + b + 1; ++i) {
        if(i==a){
            if(s[i]!='-')flg=false;
        }
        else {
            if(s[i]=='-')flg=false;
        }
    }
    if(flg)puts("Yes");
    else puts("No");
}

