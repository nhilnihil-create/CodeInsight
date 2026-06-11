#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll pow(ll n, ll p){
    if(p==0) return 1;
    ll rtn=pow(n*n, p/2);
    if(p%2==1) rtn*=n;
    return rtn;
}

vector<ll> get_prime(ll n){
    bool is_prime[n+1];
    is_prime[0]=false;
    is_prime[1]=false;
    for(ll i=2; i<=n; i++) is_prime[i]=true;
    for(ll i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(ll j=2*i; j<=n; j+=i){
                is_prime[j]=false;
            }
        }
    }
    vector<ll> p;
    for(ll i=2; i<=n; i++){
        if(is_prime[i]) p.push_back(i);
    }
    return p;
}

int main(){
    ll n, p;
    cin >> n >> p;
    vector<ll> prime=get_prime((ll)sqrt(p));
    ll l=prime.size();
    vector<ll> prime_cnt(l, 0);
    ll tmp=p;
    for(ll i=0; i<l; i++){
        while(tmp%prime[i]==0){
            tmp/=prime[i];
            prime_cnt[i]++;
        }
    }
    ll ans=1;
    for(ll i=0; i<l; i++) ans*=pow(prime[i], prime_cnt[i]/n);
    if(n==1) ans=p;
    cout << ans << endl;
    return 0;
}