#include <bits/stdc++.h>
#define rep(i,a) for(int i=0;i<int(a);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using ll = long long;
using itn = int;
using namespace std;
static const long double GRATIO=(long double)(1+sqrt(5))/2;
ll GCD(ll a, ll b){
    return b ? GCD(b, a%b) : a;
}
ll LCM(ll a, ll b){
    return a/GCD(a,b)*b;
}
void calc_comb(vector<vector<long long>> &v){
    rep(i,v.size()){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(int i=1; i<v.size(); i++){
        for(int j=1; j<i; j++){
            v[i][j]=(v[i-1][j-1]+v[i-1][j]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    ll ans=a[0];
    ll nearans=a[0];
    ll c=a[n-1]/2;
    if(a[n-1]%2) c++;
    for(int i=0; i<n-1; i++){
        if(a[i]<=c) ans=a[i];
        else{
            nearans=a[i];
            break;
        }
    }
    cout<<a[n-1]<<" ";
    if(abs(c-nearans) > abs(c-ans) ) cout<<ans<<endl;
    else cout<<nearans<<endl;
}