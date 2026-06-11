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
    int n;
    cin>>n;
    vector<ll> a(n);
    ll ave=0;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a[i]=x-i-1;
    }
    sort(a.begin(),a.end());
    ll l=a[n/2];
    ll r=INF;
    if(n>1) r=a[n/2+1];
    ll ans=0;
    ll sub=0;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-l);
        sub+=abs(a[i]-r);
    }
    ans=min(ans,sub);
    cout<<ans<<endl;
}