#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll solve(vector<ll> vec,ll st){
  if(vec.size()==0) return 0;
  if(vec[0]>st) return -1;
  return vec[0]+vec.size()-1;
}
ll ar[200005]={0};
int main(){
  ll n;
  cin>>n;
  vector<ll> vec;
  ll fst=0,past=-1,ans=0;
  bool f=true;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    if(a==past+1){
      vec.push_back(a);
    }
    else if(a>past+1) f=false;
    else{
      ll kans=solve(vec,fst);
      if(kans==-1) f=false;
      else ans+=kans;
      vec.clear();
      vec.push_back(a);
      fst=i;
    }
    past=a;
  }
  ll ka2=solve(vec,fst);
  if(ka2==-1) f=false;
  else ans+=ka2;
  cout<<(f?ans:-1)<<endl;
}
