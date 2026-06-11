#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll N;
vector<ll> a;

ll M;

class BIT{
public:

  vector<ll> bit;
  BIT(){}
  BIT(int size){
    bit.resize(size,0);
  }

  ll sum(int i){
    ll s=0;
    while(i>0){
      s+=bit[i];
      i-=i&(-i);
    }
    return s;
  }

  void add(int i,ll x){//i!=0
    while(i<bit.size()){
      bit[i]+=x;
      i+=i&(-i);
    }
  }
};


bool judge(ll mid){
    vector<ll> b=a;
    for(int i=0;i<N;i++){
        if(b[i]<mid) b[i]=-1;
        else b[i]=1;
    }
    ll sum[N+1]={};
    vector<pair<ll,int>> s;
    s.push_back(make_pair(0,0));
    for(int i=1;i<=N;i++){
        sum[i]+=sum[i-1]+b[i-1];
        s.push_back(make_pair(sum[i],i));
    }
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());

    BIT bit(N+2);
    ll res=0;
    for(int i=0;i<=N;i++){
        res+=bit.sum(s[i].second+1);
        bit.add(s[i].second+1,1);
    }

    if((M-res)*2>=M) return false;
    else return true;
}

int main(){
  cin>>N;
  M=N*(N-1)/2+N;
  for(int i=0;i<N;i++){
      ll x;
      cin>>x;
      a.push_back(x);
  }

  ll ok=0,ng=1e10;
  while(ng-ok>1){
      ll mid=(ok+ng)/2;
      if(judge(mid)) ng=mid;
      else ok=mid;
  }
  cout<<ok<<endl;

  return 0;
}
