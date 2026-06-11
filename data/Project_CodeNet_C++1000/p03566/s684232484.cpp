#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)

using namespace std;
typedef pair<int, long> P;
typedef long long int ll;

const int INF = 1<<30;

int main(){
  int n;cin>>n;
  vector<int> t(n+1), v(n);t[0]=0;
  rep(i, n)cin>>t[i+1];
  rep(i, n){
  	t[i+1]+=t[i];
  }
  rep(i, n)cin>>v[i];
  int Mt=t[n];
  int dtime=1;
  int dmv, pdmv=0;
  int ans=0;
  while(dtime<=Mt*2){
    dmv=min(dtime, Mt*2-dtime);
    rep(i, n){
      if(t[i]*2<=dtime && dtime<=t[i+1]*2){
      	dmv=min(dmv, v[i]*2);
      }else if(dtime<t[i]*2){
        dmv=min(dmv, (t[i]*2-dtime)+v[i]*2);
      }else{
      	dmv=min(dmv, (dtime-t[i+1]*2)+v[i]*2);
      }
    }
    // cout<<dtime*0.5<<"sec: "<<dmv*0.5<<"m/s"<<endl;
    ans+=(dmv+pdmv);
    pdmv=dmv;
    dtime++;
  }
  cout<<fixed<<setprecision(10)<<ans*0.125<<endl;
  return 0;
}

