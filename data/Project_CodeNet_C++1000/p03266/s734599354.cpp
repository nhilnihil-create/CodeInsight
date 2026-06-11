#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
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
ll se=0;
ll sume(vector<int> a,int n){

}
int main(){
    ll n,k;cin>>n>>k;
    ll ans=(n/k)*(n/k)*(n/k);
    if(k%2==0){
        ans+=(n/(k/2)-n/k)*(n/(k/2)-n/k)*(n/(k/2)-n/k);
    }
    cout<<ans<<endl;
    return 0;
}