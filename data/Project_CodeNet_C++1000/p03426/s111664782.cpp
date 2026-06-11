#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1001001001;


int main() {
  int h,w,d;
  cin>>h>>w>>d;
  vector<P> a(1000000);
  rep(i,h)rep(j,w){
    ll a1;
    cin>>a1;
    a[a1]=make_pair(i,j);
  }
  int q;

  vector<ll> v[d+5];//あまりごとに

  for(int i=0;i<d;i++){
    ll now=i;
    if (i==0)now=d;
    P pos=a[now];
    v[i].push_back(0);
    ll cnt=0;
    while (now<=h*w){
      now+=d;
      P posnew=a[now];
      ll ad=abs(posnew.first-pos.first)+abs(posnew.second-pos.second);
    //  cout<<pos.first<<'f'<<pos.second<<"s"<<endl;
    //  cout<<posnew.first<<'f'<<posnew.second<<"s"<<endl;

    //  cout<<ad<<'i'<<i<<"now"<<now<<endl;
      cnt+=ad;
      v[i].push_back(cnt);
      pos=a[now];
    }
  }

  cin>>q;
  rep(i,q){
    int l1,r1;
    cin>>l1>>r1;

    ll D=l1%d;
    ll s1=(l1-D)/d;
    ll f1=(r1-D)/d;
    if (D==0){
      s1--;f1--;
    }
    //cout<<s1<<"s1"<<f1<<"f1"<<endl;
    ll cnt=v[D][f1]-v[D][s1];
    cout<<cnt<<endl;


  }
return 0;

}
