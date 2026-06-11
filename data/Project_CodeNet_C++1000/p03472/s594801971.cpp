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
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;


int main(){
    ll n,h;
    cin>>n>>h;
    vector<ll> b(n);
    ll a=0;
    for(ll i=0;i<n;i++){
        ll A;
        cin>>A>>b[i];
        a=max(a,A);
    }
    sort(b.begin(),b.end());
    ll ans=0;
    for(ll i=n-1;i>=0 && h>0 && b[i]>a;i--){
        ans++;
        h-=b[i];
    }
    if(h>0) ans+=(h+a-1)/a;
    cout<<ans<<endl;

}