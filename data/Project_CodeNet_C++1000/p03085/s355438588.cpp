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
   string a,b;cin >>a;
   ll n=a.size();
    for (int i = 0; i < n; ++i) {
        if(a[i]=='A')b+='T';
        else if(a[i]=='T')b+='A';
        else if(a[i]=='C')b+='G';
        else b+='C';
    }
    cout <<b<<endl;
   return 0;
}