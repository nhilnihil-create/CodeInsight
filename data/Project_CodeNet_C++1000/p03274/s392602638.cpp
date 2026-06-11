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
    ll n,k;
    cin>>n>>k;
    vector<ll> x(n);
    for(ll i=0;i<n;i++){
        cin>>x[i];
    }
    ll ans=INF;
    for(ll i=0;i<n;i++){
        ll l=i;
        ll r=i+k-1;
        if(r>=n)  break;
        if(x[l]<0 && x[r]<0){
            ans=min(ans,-x[l]);
        }else if(x[l]<0 && x[r]>=0){
            ans=min(ans,min(-2*x[l]+x[r],-x[l]+2*x[r]));
        }else{
            ans=min(ans,x[r]);
        }
    }
    cout<<ans<<endl;

}