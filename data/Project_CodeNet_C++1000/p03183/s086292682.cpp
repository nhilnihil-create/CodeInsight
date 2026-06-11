#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

vector<vector<ll> >v;
vector<vector <ll>>dp;

bool compare(vector<ll>&a,vector<ll>&b){
ll w1 = a[0],s1=a[1],w2=b[0],s2=b[1];
return w1+s1 > w2+s2;
}
void solve(){
ll n;cin>>n;
v.resize(n,vector<ll>(3));
dp.resize(n,vector<ll>(10001));
for(ll i=0;i<n;i++){
cin>>v[i][0]>>v[i][1]>>v[i][2];
}
sort(v.begin(),v.end(),compare);
for(ll i=0;i<=v[0][1];i++){
dp[0][i]=v[0][2];
}
for(ll i=1;i<n;i++){
for(ll j=0;j<=10001;j++){
dp[i][j] = dp[i-1][j];
if(j<=v[i][1]){
dp[i][j] = max(dp[i-1][j],v[i][2]+(j+v[i][0]<=10000 ? (dp[i-1][j+v[i][0]]):0));
}
}
}
cout <<dp[n-1][0]<<"\n";

}

int main(){
// cin.tie(0);
// cout.tie(0);
// cin.sync_with_stdio(0);
// cout.sync_with_stdio(0);

/*
    #ifndef ONLINE_JUDGE
        freopen("input.txt",  "r",  stdin);
        freopen("output.txt", "w", stdout);
    #endif
//*/

        
cout.precision(10);
int t=1;//cin>>t;
while(t--){
    solve();
}
return 0;
}