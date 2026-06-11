#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const ll INF=1001001001001001;

int main() {
  ll d,g;
  cin>>d>>g;
  vector<P> v(d);
  rep(i,d){
    cin>>v[i].first;
    cin>>v[i].second;
  }


  ll ans=INF;
  for(ll i=1;i<(1<<d);i++){
    ll s=0;
    ll cnt=0;
    rep(j,d){
      if (i&(1<<j)){
        if (g<v[j].first*100*(j+1)){
          cnt+=(g+100*(j+1)-1)/(100*(j+1));
        //  cout<<599/200;
      //    cout<<(g+100*(j+1)-1)<<' '<<100*(j+1)<<' '<<cnt<<' '<<j<<'j'<<endl;
          s=g;
        }
        //cout<<cnt<<endl;

        else{
          s+=(v[j].first*100*(j+1));
    //      cout<<s<<'s'<<j<<'j'<<endl;
          s+=v[j].second;
          cnt+=v[j].first;
        }
      }
    }
  //  cout<<s<<' '<<i<<'I'<<endl;

    if(s<g){
    //  cout<<s<<' '<<i<<'I'<<endl;
      ll temp=INF;
      rep(j,d){
      if (!(i&(1<<j))){
      //sav  cout<<j<<'j'<<endl;
        ll now=(g-s+(100*(j+1))-1)/(100*(j+1));
    //    cout<<now<<' '<<j<<'n'<<endl;
        if (now<=v[j].first){
          temp=min(temp,now);
      //    cout<<temp<<' '<<j<<'J'<<endl;
        }
      }
      }
      cnt+=temp;

    }
  //  cout<<cnt<<' '<<i<<"nct"<<endl;
      ans=min(cnt,ans);
  }
  cout<<ans;

}
