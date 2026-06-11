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

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    a[0]=0;
    for(ll i=1;i<=n;i++){
        ll _;
        cin>>_;
        a[i]=a[i-1]+_;
    }
    map<ll,ll> mp;
    ll ans=0;
    for(ll i=0;i<=n;i++){
        ans+=mp[a[i]];
        mp[a[i]]+=1;
    } 
    cout<<ans<<endl;
}