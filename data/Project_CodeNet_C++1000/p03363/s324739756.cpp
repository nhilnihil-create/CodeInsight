#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

lli comb(lli a){
    lli b;
    b=a*(a-1)/2;
    return b;
}

int main() {
    lli sum=0,n,a,ans=0;
    map<lli,lli> mp;
    lli i,j,k;
    cin>>n;
    mp[0]++;
    rep(i,0,n){
        cin>>a;
        sum+=a;
        mp[sum]++;
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        ans+=comb(itr->second);
    }
    cout<<ans<<endl;
}
