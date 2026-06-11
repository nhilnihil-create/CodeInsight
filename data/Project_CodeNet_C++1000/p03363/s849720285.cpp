#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    int n;cin>>n;
    vector<int> a(n);
    map<ll,ll> cnt;
    vector<ll> sum(n+1,0);
    cnt[0]++;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
        cnt[sum[i+1]]++;
    }
    ll ans=0;
    for(auto it:cnt){
        ans+=(it.second)*(it.second-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}