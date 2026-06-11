#include<bits/stdc++.h>
using namespace std;
// #define mod 1000000007
#define ll long long int

vector<vector <ll>>v;
// vector<vector <ll>>dp;
ll dp[1005][10005] = {};
bool compare(vector<ll>&a,vector<ll>&b){
ll w1 = a[0],s1=a[1],w2=b[0],s2=b[1];
return w1+s1 > w2+s2;
}
void solve(){
ll n;cin>>n;
v.resize(n,vector<ll>(3));
// dp.resize(1001,vector<ll>(10001,0));
for(ll i=0;i<n;i++){
cin>>v[i][0]>>v[i][1]>>v[i][2];
}
sort(v.begin(),v.end(),compare);
    for(int j = 0; j <= 10000; j++)
    {
        if(v[0][1] >= j)
            dp[0][j] = v[0][2];
        else dp[0][j] = 0;
    }

for(int i = 1; i < n; i++)
{
    for(int j = 0; j <= 10000; j++)
    {
        ll op1 = dp[i-1][j];
        ll op2 = (v[i][1] >= j) ? (v[i][2] + ((j + v[i][0] > 10000)?0:dp[i-1][j+v[i][0]])) : 0;
        dp[i][j] = max(op1, op2);
    }
}
cout<< dp[n-1][0]<<endl;


}

int main(){
// cin.tie(0);
// cout.tie(0);
// cin.sync_with_stdio(0);
// cout.sync_with_stdio(0);
///*
    #ifndef ONLINE_JUDGE
        freopen("input.txt",  "r",  stdin);
        freopen("output.txt", "w", stdout);
    #endif
//*/
// cout.precision(10);
int t=1;//cin>>t;
while(t--){
    solve();
}
return 0;
}
