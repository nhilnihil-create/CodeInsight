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
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    if(k%2){
        n/=k;
        ans=n*n*n;
    }else{
        ll l=n/k;
        ll m;
        if(n%k>=k/2){
            m=l+1;
        }else{
            m=l;
        }
        ans=l*l*l+m*m*m;
    }
    cout<<ans<<endl;
}