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
    int n;
    cin>>n;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        mp[a]++;

    }
    ll ans=0;
    for(auto p:mp){
        ll key=p.first;
        ll num=p.second;
        if(num<key){
            ans+=num;
        }else{
            ans+=num-key;
        }
    }
    cout<<ans<<endl;
    
    
}