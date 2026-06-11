#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main() {
    ll ans=0;
    vector<ll>cnt(5,0);
    ll n;cin >>n;
    char c[5]={'M','A','R','C','H'};
    for (int i = 0; i < n; ++i) {
        string s;cin >>s;
        for (int j = 0; j < 5; ++j){
            if(s[0]==c[j])cnt[j]++;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j =i+1; j <4; ++j) {
            for (int k = j+1; k <5; ++k) {
                ans+=cnt[i]*cnt[j]*cnt[k];
            }
        }
    }
    cout <<ans <<endl;
}
