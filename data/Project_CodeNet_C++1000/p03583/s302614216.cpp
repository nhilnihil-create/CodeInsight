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
    for (int x = 1; x <=3500; ++x) {
        for (int y = 1; y <=3500; ++y) {
            ll s=n*x*y;
            ll t=4*x*y-n*y-n*x;
            if(t==0)continue;
            if(s%t==0){
                if(s/t>0){
                    cout <<x<<" "<<y<<" "<<s/t<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}