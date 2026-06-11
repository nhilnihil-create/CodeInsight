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
const ll INF=4999999996000000001;
ll frac[1001001];

void output(ll a){
    string res;
    for(int i=0;i<12;i++){
        res+=(char)('0'+a%10);
        a/=10;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}

int main(){
    ll n,m;
    cin>>n>>m;
    map<ll,vector<P> > mp;
    for(ll i=0;i<m;i++){
        ll p;
        ll y;
        cin>>p>>y;
        mp[p].push_back(P(y,i));
    }
    vector<ll> ans(m);
    for(auto vp:mp){
        ll pre=vp.first;
        ll count=1;
        sort(vp.second.begin(),vp.second.end());
        for(auto p:vp.second){
            ll y=p.first;
            ll i=p.second;
            ans[i]=count;
            ans[i]+=pre*1000000;
            count++;
        }
    }

    for(int i=0;i<m;i++){
        output(ans[i]);
    }

}