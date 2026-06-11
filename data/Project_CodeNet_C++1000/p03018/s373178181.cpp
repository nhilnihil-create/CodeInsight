#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    string s;cin >>s;
    ll n=s.size();
    ll a=0;ll ans=0;
    for (int i = 0; i < n; ++i) {
        if(s[i]=='A')a++;
        else if(s[i]=='B'){
            if(i+1>=n)continue;
            else if(s.substr(i,2)=="BC") {
                ans += a;
                i++;
            }
            else {
                a=0;
            }
        }
        else if(s[i]=='C'){
            a=0;
           // cout<<"aaaaa"<<endl;
        }
    }
    cout <<ans <<endl;
    return 0;
}