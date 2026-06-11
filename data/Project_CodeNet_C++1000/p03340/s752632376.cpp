#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
ll num[21];

bool flag(){
    bool f=true;
    for(ll i=0;i<21;i++){
        if(num[i]>1) f=false;
    }
    return f;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll l=0;
    ll r=0;
    ll ans=0;
    while(r<n){
        while(true && r<n){
            ans+=r-l+1;
            for(ll i=0;i<21;i++){
                num[i]+=(a[r]>>i & 1);
            }
            if(!flag()){
                ans-=r-l+1;
                break;
            }
            //cout<<num[2]<<num[1]<<num[0]<<endl;
            //cout<<l<<" "<<r<<" "<<ans<<endl;
            r++;
        }
        while(l<r){
            for(ll i=0;i<21;i++){
                num[i]-=(a[l]>>i & 1);
            }
            l++;
            if(flag()){
                for(ll i=0;i<21;i++){
                    num[i]-=(a[r]>>i & 1);
                }
                break;
            }
        }
    }
    cout<<ans<<endl;
}