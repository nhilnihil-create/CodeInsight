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
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    for(ll b=k+1;b<=n;b++){
        ll m=(n-k)/b;
        ans+=m*(b-k);
        ans+=min(n,(m+1)*b-1)-(m*b+k)+1;
        //cout<<"b="<<b<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}