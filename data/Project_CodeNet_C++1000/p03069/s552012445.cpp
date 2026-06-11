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
    int n;cin >>n;
    string s;cin >>s;
    ll ans=0;
    ll l=0,r=0;//l:cnt black r:cnt white
    for (int i = 0; i < n; ++i) {
        if(s[i]=='.')r++;
    }
    ans=r;
    for (int i = 0; i <n; ++i) {
        if(s[i]=='#')l++;
        else {
            r--;
        }
        ans=min(ans,l+r);
    }
    cout <<ans<<endl;
}
