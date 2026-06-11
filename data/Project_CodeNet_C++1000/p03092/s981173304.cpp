#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;


int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<pll> A(n);
    for(int i=0;i<n;i++){cin>>A[i].F; A[i].S=i;}
    sort(A.begin(),A.end());
    vector<ll> dp(n+1,0);
    vector<ll> next(n+1,0);
    for(auto &I:A){
        ll mi=E;
        for(int i=0;i<=n;i++){
            mi=min(mi,dp[i]);
            if(i<=I.S){next[i]=mi+b;}
            else if(i==I.S+1){next[i]=mi;}
            else{next[i]=mi+a;}
        }
        dp=next;
    }
    ll ans=E;
    for(auto &I:dp){ans=min(ans,I);}
    cout<<ans<<endl;
    
    
    return 0;
}
