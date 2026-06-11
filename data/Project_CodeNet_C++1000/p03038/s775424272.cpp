#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll N,M;
  cin >> N >> M;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  
  vector<pair<ll,ll>> card(M);
  for(ll i=0;i<M;i++){
    ll b,c;
    cin >> b >> c;
    card[i]=make_pair(c,b);
  }
  sort(card.begin(),card.end());
  
  ll now =M-1;
  for(ll i=0;i<N;i++){
    if(card[now].second<=0){
      now--;
    }
    if(vec[i]<card[now].first){
      vec[i]=card[now].first;
      card[now].second--;
    }
  }
  
  ll ans=0;
  for(ll i=0;i<N;i++){
    ans +=vec[i];
  }
  cout << ans <<endl;
}

  