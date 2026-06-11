#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int n;
vector<vector<vector<double> > >dp;
double exptimes(int ones,int twos,int threes){
    if(ones<0 || twos<0 || threes<0){
        return 0;
    }
    if(dp[ones][twos][threes]>=0){
        return dp[ones][twos][threes];
    }
    dp[ones][twos][threes] = n+ ones*exptimes(ones-1,twos,threes) +twos*exptimes(ones+1,twos-1,threes) + threes*exptimes(ones,twos+1,threes-1);
    dp[ones][twos][threes] /= (ones+twos+threes);
    return dp[ones][twos][threes];
}
void solve(){
  cin>>n;
  dp.resize(n+1,vector<vector<double>>(n+1,vector<double>(n+1,-1)));
  dp[0][0][0]=0;
  int ones=0,twos=0,threes=0;
  for(int i=0;i<n;i++){
    int a;cin>>a;
    if(a==1){
        ones++;
    }else if(a==2){
        twos++;
    }else{
        threes++;
    }
  }
  cout<<exptimes(ones,twos,threes)<<"\n";
}

int main(){
//    cin.tie(0);
//    cout.tie(0);
//    cin.sync_with_stdio(0);
//    cout.sync_with_stdio(0);

    cout.precision(14);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
