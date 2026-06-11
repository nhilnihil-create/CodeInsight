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
#include<unordered_map>
#include<fstream>
#include<list>
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

vector<ll> a;
vector<ll> A;
ll n,x;

ll count(ll i){
    ll count=A[i];
    ll r=1;
    for(ll t=0;t<n;t++){
        if(t%(i+1)==0){r++;}
        count+=(2*r-1)*a[t];
    }
    return count+x*n;
}



int main(){
    cin>>n>>x;
    a.resize(n);
    for(int i=0;i<n;i++){cin>>a[n-1-i];}
    A.resize(n);
    A[0]=2*a[0]+x;
    for(ll i=1;i<n;i++){
        A[i]=2*a[i]+A[i-1]+x;
    }
    ll l=0,r=n;
    while(r-l>10){
        ll m=l+(r-l)/2;
        ll d=m+1;
        if(count(m)>count(d)){l=d;}
        else{r=d;}
    }
    ll ans=E;
    for(ll i=l;i<r && i<n;i++){
        ans=min(ans,count(i));
    }
    cout<<ans<<endl;
    
    
    return 0;
}
