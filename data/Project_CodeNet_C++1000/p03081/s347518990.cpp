#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int N,Q;
string s;
vector<char>t,d;

bool left(int now){
  for(int i=0;i<Q;i++){
    if(s[now]==t[i]){
      if(d[i]=='L')now--;
      if(d[i]=='R')now++;
    }
    if(now<0)return true;
  }
  return false;
}

bool right(int now){
  for(int i=0;i<Q;i++){
    if(s[now]==t[i]){
      if(d[i]=='L')now--;
      if(d[i]=='R')now++;
    }
    if(now>=N)return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin>>N>>Q;
  cin>>s;
  t.resize(Q);
  d.resize(Q);
  for(int i=0;i<Q;i++)cin>>t[i]>>d[i];

  //左に落ちる
  int l1=0;
  int r1=N;
  int m1;
  while(r1-l1>1){
    m1=(l1+r1)/2;
    if(left(m1))l1=m1;
    else r1=m1;
  }

  int l2=0;
  int r2=N;
  int m2;
  while(r2-l2>1){
    m2=(l2+r2)/2;
    if(right(m2))r2=m2;
    else l2=m2;
  }
  cout<<N-min(l1+N-l2,N)<<endl;
  return 0;
}
