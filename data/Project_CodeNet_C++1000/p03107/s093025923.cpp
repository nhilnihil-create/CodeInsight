#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pairs;

#define MOD 998244353


ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

bool primeNumber(ll n){
    if(n < 2) return false;
    else{
        for(ll i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
}


const double PI = acos(-1);
const int M = 1000005;

int main(){
    string s;
    cin>>s;
    
    vector<ll> cnt(2,0);
    
    for(ll i = 0; i<s.size(); i++){
        cnt[s[i] - '0']++;
    }
    ll ans = min({cnt[1], cnt[0]}) * 2;
    
    cout<<ans<<endl;
    return 0;
}
