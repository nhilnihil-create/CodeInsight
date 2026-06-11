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
   bool flg=true;
   if(s[0]!='A')flg=false;
   ll cnt=0;
    for (int i = 2; i <s.size()-1; ++i) {
        if(s[i]=='C')cnt++;
    }
    if(cnt!=1)flg=false;
    for (int i = 1; i < s.size(); ++i) {
        if(s[i]<'a'||s[i]>'z'){
            if(i==s.size()-1||i==1)flg=false;
            if(s[i]!='C')flg=false;
        }
    }
    if(flg)puts("AC");
    else puts("WA");
   return 0;
}