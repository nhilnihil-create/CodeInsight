#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 10007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  ll N,H; cin>>N>>H;
  vector<tuple<ll,char,int>> katana;
  rep(i,N){
    ll a,b; cin>>a>>b;
    katana.push_back(make_tuple(a,'a',i+1));
    katana.push_back(make_tuple(b,'b',i+1));
  }
  sort(katana.begin(),katana.end());
  reverse(katana.begin(),katana.end());
  ll res = 0;
  rep(i,2*N+10){
    if(get<1>(katana.at(i))=='a'){
      ll tmp = get<0>(katana.at(i));
      res+=((H-1)/tmp+1);
      cout<<res<<endl;
      return 0;
    }else{
      H-=get<0>(katana.at(i));
      res++;
    }
    if(H<=0)break;
  }   
  cout<<res<<endl;
}
