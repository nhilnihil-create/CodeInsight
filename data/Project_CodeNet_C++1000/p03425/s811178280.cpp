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
    ll n;cin >>n;
    vector<ll>a(5,0);
    for (int i = 0; i < n; ++i) {
        string s;cin >>s;
        if(s[0]=='M')a[0]++;
        if(s[0]=='A')a[1]++;
        if(s[0]=='R')a[2]++;
        if(s[0]=='C')a[3]++;
        if(s[0]=='H')a[4]++;
    }
    ll ans=0;
    for (int j = 0; j < 3; ++j) {
        for (int i = j+1; i < 4; ++i) {
            for (int k = i+1; k < 5; ++k) {
                ans+=a[j]*a[i]*a[k];
            }
        }
    }
    cout <<ans <<endl;
    return 0;
}