#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  int A,B,Q;
  cin>>A>>B>>Q;
  vector<ll> s(A),t(B),x(Q);
  for(int i=0;i<A;i++){
    cin>>s.at(i);
  }
  for(int i=0;i<B;i++){
    cin>>t.at(i);
  }
  for(int i=0;i<Q;i++){
    cin>>x.at(i);
  }
  for(int i=0;i<Q;i++){
    int k1=lower_bound(s.begin(),s.end(),x.at(i))-s.begin();
    int k2=lower_bound(t.begin(),t.end(),x.at(i))-t.begin();
    ll ans=20000000000;
    if(k1==0&&k2==0){
      ans=min<ll>(ans,max<ll>(s.at(k1)-x.at(i),t.at(k2)-x.at(i)));
    }else if(k1==0){
      if(k2!=B){
        ans=min<ll>(ans,max<ll>(s.at(k1)-x.at(i),t.at(k2)-x.at(i)));
      }
      ans=min<ll>(ans,s.at(k1)-x.at(i)+2*(x.at(i)-t.at(k2-1)));
      ans=min<ll>(ans,2*(s.at(k1)-x.at(i))+x.at(i)-t.at(k2-1));
    }else if(k2==0){
      if(k1!=A){
        ans=min<ll>(ans,max<ll>(s.at(k1)-x.at(i),t.at(k2)-x.at(i)));
      }
      ans=min<ll>(ans,x.at(i)-s.at(k1-1)+2*(t.at(k2)-x.at(i)));
      ans=min<ll>(ans,2*(x.at(i)-s.at(k1-1))+t.at(k2)-x.at(i));
    }else if(k1==A&&k2==B){
      ans=min<ll>(ans,max<ll>(x.at(i)-s.at(k1-1),x.at(i)-t.at(k2-1)));
    }else if(k1==A){
      ans=min<ll>(ans,max<ll>(x.at(i)-s.at(k1-1),x.at(i)-t.at(k2-1)));
      ans=min<ll>(ans,x.at(i)-s.at(k1-1)+2*(t.at(k2)-x.at(i)));
      ans=min<ll>(ans,2*(x.at(i)-s.at(k1-1))+t.at(k2)-x.at(i));
    }else if(k2==B){
      ans=min<ll>(ans,max<ll>(x.at(i)-s.at(k1-1),x.at(i)-t.at(k2-1)));
      ans=min<ll>(ans,s.at(k1)-x.at(i)+2*(x.at(i)-t.at(k2-1)));
      ans=min<ll>(ans,2*(s.at(k1)-x.at(i))+x.at(i)-t.at(k2-1));
    }else{
      ans=min<ll>(ans,max(s.at(k1)-x.at(i),t.at(k2)-x.at(i)));
      ans=min<ll>(ans,max(x.at(i)-s.at(k1-1),x.at(i)-t.at(k2-1)));
      ans=min<ll>(ans,x.at(i)-s.at(k1-1)+2*(t.at(k2)-x.at(i)));
      ans=min<ll>(ans,2*(x.at(i)-s.at(k1-1))+t.at(k2)-x.at(i));
      ans=min<ll>(ans,s.at(k1)-x.at(i)+2*(x.at(i)-t.at(k2-1)));
      ans=min<ll>(ans,2*(s.at(k1)-x.at(i))+x.at(i)-t.at(k2-1));
    }
    cout<<ans<<endl;
  }
}
