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
typedef long double D;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;



int main(){
    ll n;
    cin>>n;
    vector<ll> T(n);
    ll sum=0;
    for(auto &I:T){cin>>I; sum+=I; I=sum;}
    vector<ll> A(sum);
    ll l=0;
    for(int i=0;i<n;i++){
        ll v;
        cin>>v;
        while(l<T[i]){A[l]=v; l++;}
    }
    ll mi=0;
    vector<ll> dp1(sum,0);
    vector<ll> dp2(sum,0);
    for(int i=0;i+1<sum;i++){
        mi++;
        mi=min(mi,A[i]);
        dp1[i+1]=mi;
    }
    mi=0;
    for(ll i=sum-1;i>0;i--){
        mi++;
        mi=min(mi,A[i]);
        dp2[i-1]=mi;
    }
    mi=0;
    double ans=0;
    for(int i=0;i+1<sum;i++){dp2[i]=min(dp2[i],dp1[i+1]);}
    ll s=0;
    for(int i=0;i<sum;i++){
        //cout<<i<<" "<<dp2[i]<<endl;
        if(s<dp2[i]){
            ans+=s+1.0/2;
            s++;
        }
        else if(s>dp2[i]){
            ans+=s-1.0/2;
            s--;
        }
        else{
            if(A[i]>s){ans+=s+1.0/4;}
            else{ans+=s;}
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
    
    
    return 0;
}
