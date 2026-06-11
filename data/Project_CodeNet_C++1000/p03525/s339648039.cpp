#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> cnt(13,0),now(24,0),ser;
  cnt[0]=1;
  rep(i,n){
    int d;
    cin>>d;
    cnt[d]++;
  }
  rep(i,13){
    if(i==0 || i==12){
      if(cnt[i]>=2){
        cout<<0<<endl;
        return 0;
      }else if(cnt[i]==1) now[i]++;
    }else if(cnt[i]>=3){
      cout<<0<<endl;
      return 0;
    }else if(cnt[i]==2){
      now[i]++;
      now[24-i]++;
    }else if(cnt[i]==1) ser.push_back(i);
  }
  int m=len(ser);
  int ans=0;
  rep(i,1<<m){
    vector<int> cop(now);
    int ch=1e9;
    rep(j,m){
      if((1<<j) & i) cop[ser[j]]++;
      else cop[24-ser[j]]++;
    }
    vector<int> ind;
    rep(j,24){
      if(cop[j]) ind.push_back(j);
    }
    ind.push_back(24);
    FOR(j,1,len(ind)){
      ch=min(ch,ind[j]-ind[j-1]);
    }/*
    rep(j,24) cout<<cop[j];
    cout<<' '<<ch<<endl;*/
    //cout_vec(ind);
    ans=max(ans,ch);
  }
  cout<<ans<<endl;
}