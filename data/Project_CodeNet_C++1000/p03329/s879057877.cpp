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
    ll ans=INF;
    for(ll i=0;i<=n;i++){
        ll cc=0;
        ll mon=i;
        while(mon>0){
            cc+=mon%6;
            mon/=6;
        }
        mon=n-i;
        while(mon>0){
            cc+=mon%9;
            mon/=9;
        }
        ans=min(ans,cc);
    }   
    cout<<ans<<endl;
}