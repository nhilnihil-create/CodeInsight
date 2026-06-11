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
    string s;
    cin>>s;
    vector<ll> E(n,0);
    vector<ll> W(n,0);
    if(s[0]=='W') W[0]=1;
    if(s[n-1]=='E') E[n-1]=1;
    for(ll i=1;i<n;i++){
        if(s[i]=='W') W[i]=1;
        W[i]+=W[i-1];
    }
    for(ll i=n-2;i>=0;i--){
        if(s[i]=='E') E[i]=1;
        E[i]+=E[i+1];
    }
    ll ans=INF;
    for(ll i=0;i<n;i++){
        ans=min(ans,W[i]+E[i]-1);
    }
    cout<<ans<<endl;
}