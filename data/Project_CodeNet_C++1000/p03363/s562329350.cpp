#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define DEBUG 0 
#define LIMIT (LONG_MAX / 10)
#define POSITIVE_LAST_D (LONG_MAX % 10)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    vector<ll> csum(n+1,0);
    rep(i,n)csum[i+1]=csum[i]+a[i];
    map<ll,ll> nums;
    rep(i,n+1)nums[csum[i]]++;

    ll ans=0;
    for(auto iter:nums){
        ll  num=iter.second;
        ans+=num*(num-1)/2;
    }
    cout<<ans<<endl;
        
    
}

