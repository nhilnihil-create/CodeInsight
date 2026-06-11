#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


vector<vector<ll> >v;
vector<vector<ll> >dp;

bool compare(vector<ll>&a,vector<ll>&b){
    ll w1 = a[0],s1=a[1],w2=b[0],s2=b[1];
    return w1+s1 > w2+s2;
}
void printdp(){
    cout <<"--------------start---------------\n";
    for(ll i=0;i<dp.size();i++){
        for(ll j=0;j<dp[0].size();j++){
            cout << dp[i][j]<<" ";
        }
        cout <<"\n";
    }
    cout <<"--------------end---------------\n";
}
void solve(){
  ll n;cin>>n;
  v.resize(n,vector<ll>(3));
  dp.resize(n,vector<ll>(10002));
  for(ll i=0;i<n;i++){
    cin>>v[i][0]>>v[i][1]>>v[i][2];
  }
  sort(v.begin(),v.end(),compare);
  for(ll i=0;i<=v[0][1];i++){
    dp[0][i]=v[0][2];
  }
  //printdp();
  for(ll i=1;i<n;i++){
        //cout<<v[i][2]<<"n";
    for(ll j=0;j<10002;j++){
        //cout << i<<" "<<j<<"\n";
        ll a = dp[i-1][j];
        ll b=0;
        if(j<=v[i][1]){
            b = v[i][2] + ((j+v[i][0]<10002) ? (dp[i-1][j+v[i][0]]):0);
        }
        dp[i][j] = max(a,b);
        //cout <<"dpij: " <<dp[i-1][j]<<" "<<dp[i][j]<<"\n";
    }
    //printdp();
  }
  cout <<dp[n-1][0]<<"\n";
}

int main(){
//    cin.tie(0);
//    cout.tie(0);
//    cin.sync_with_stdio(0);
//    cout.sync_with_stdio(0);

    //cout.precision(10);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
