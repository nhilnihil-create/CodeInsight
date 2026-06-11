#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
#include <cassert>
using namespace std;
using ll = long long;
using plong = pair<ll,ll>;
ll MOD=998244353;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll N;cin>>N;
    for(ll h=1;h<=3500;h++){
        for(ll n=1;n<=3500;n++){
            ll mo = 4*n*h-N*n-N*h;
            if(mo==0)continue;
            if((N*h*n)%mo==0&&(N*h*n)/mo>0){
                cout<<h<<" "<<n<<" "<<(N*h*n)/mo<<endl;
                return 0;
            }
        }
    }
}
