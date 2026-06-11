#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)




int main(){
  
  ll n,m;
  cin>>n>>m;
  
  vector<ll> data(n);
  rep(i,n){
    ll tmp;
    cin>>tmp;
    data.at(i)=tmp;
  }
  
  vector<pair<ll,ll>> operations(m);
  rep(i,m){
    ll b,c;
    cin>>b>>c;
    auto tmp=make_pair(c,b);
    operations.at(i)=tmp;
  }
  
  sort(operations.begin(),operations.end());
  reverse(operations.begin(),operations.end());
  

  sort(data.begin(),data.end());
  
  
  vector<ll> lesscount(m);
  rep(i,m){
    ll ci=operations.at(i).first;
    ll dis=distance(data.begin(),lower_bound(data.begin(),data.end(),ci));
    lesscount.at(i)=dis;
  }
  
  
  
  ll changetimes=0;
  
  rep(i,m){
    if (lesscount.at(i)>changetimes){    
      ll change=min(lesscount.at(i)-changetimes,operations.at(i).second);
      for (ll j=changetimes;j<changetimes+change;j++){
        data.at(j)=operations.at(i).first;
      }
      changetimes+=change;
    }
    else {
      break;
    }
  }

  ll answer=0;

  rep(i,n){
    answer+=data.at(i);
  }
  
  cout<<answer<<endl;
   

}








