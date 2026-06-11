#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main(){
   int n;cin >>n;
   string s;cin >>s;
   int q;cin>>q;
   vector<int>k(q);
    for (int i = 0; i < q; ++i) {
        cin >>k[i];
    }
    for (int i = 0; i < q; ++i) {
        ll ans=0;
        ll m=0,c=0,mc=0;
        for (int j = 0; j <k[i]; ++j) {
            if(s[j]=='M')m++;
            if(s[j]=='C'){
                c++;
                mc+=m;
            }
        }
        for (int j = 0; j < n - k[i]; ++j) {
            if(s[j]=='D')ans+=mc;
            if(s[j]=='M'){
                m--;
                mc-=c;
            }
            if(s[j]=='C')c--;
            if(s[j+k[i]]=='M')m++;
            if(s[j+k[i]]=='C'){
                c++;
                mc+=m;
            }
        }
        for (int l =n-k[i]; l <n; ++l) {
            if(s[l]=='D')ans+=mc;
            if(s[l]=='M'){
                m--;
                mc-=c;
            }
            if(s[l]=='C')c--;
        }
        cout<<ans <<endl;
    }
}
