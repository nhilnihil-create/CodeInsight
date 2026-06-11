#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    int ans=INF;
    for (int i = 0; i < 1000; ++i) {
        if(i>=n){
            ll c=i;
            set<ll>s;
            while(c>0){
                s.insert(c%10);
                c/=10;
            }
            if(s.size()==1)ans=min(ans,i);
        }
    }
    cout <<ans <<endl;
    return 0;
}