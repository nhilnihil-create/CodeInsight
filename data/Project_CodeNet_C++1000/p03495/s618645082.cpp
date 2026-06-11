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
vector<ll> v(200010,0);

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        v[a[i]]++;
    }
    vector<ll> q(0);
    ll kind=0;
    for(ll i=0;i<200010;i++){
        if(v[i]!=0){
            kind++;
            q.push_back(v[i]);
        }
    }
    ll ans=0;
    ll i=0;
    sort(q.begin(),q.end());
    while(kind-k>0){
        ans+=q[i];
        i++;
        kind--;
    }
    cout<<ans<<endl;
}