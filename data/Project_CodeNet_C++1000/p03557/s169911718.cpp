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
typedef pair<int,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999999;



int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    vector<ll> B(n,0);
    for(int i=0;i<n;i++){
        ll bn=b[i];
        ll num=c.end()-upper_bound(c.begin(),c.end(),bn);
        B[i]=num;
    }
    for(int i=n-2;i>=0;i--){
        B[i]+=B[i+1];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll an=a[i];
        int itr=upper_bound(b.begin(),b.end(),an)-b.begin();
        ans+=B[itr];
    }
    cout<<ans<<endl;
}