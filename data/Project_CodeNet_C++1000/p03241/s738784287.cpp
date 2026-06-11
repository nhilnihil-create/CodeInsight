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
    ll n,m;
    cin>>n>>m;
    ll k=m/n;
    ll ans=1;
    for(ll i=1;i<=min(k,(ll)sqrt(m));i++){
        if(m%i==0){
            if(m/i<=k){
                ans=max(ans,m/i);
            }else{
                ans=max(ans,i);
            }
        }
    }
    cout<<ans<<endl;
}