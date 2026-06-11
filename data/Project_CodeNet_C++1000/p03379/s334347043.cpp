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
    vector<ll> a(n);
    vector<ll> x(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        x[i]=a[i];
    }
    sort(x.begin(),x.end());
    ll l=x[n/2-1];
    ll r=x[n/2];
    vector<ll> ans(n);
    for(ll i=0;i<n;i++){
        if(a[i]<=l){
            ans[i]=r;
        }else{
            ans[i]=l;
        }
    }
    for(ll i=0;i<n;i++) cout<<ans[i]<<endl;
}