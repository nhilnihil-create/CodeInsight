#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow(ll x,ll n){
  ll res=1;
  while(n>0){
    if(n & 1){
      res*=x;
      x*=x;
      n >>= 1;
    }
  }
  return res;
}

pair<int,int> ftoS(int x){
  if(x==0){
    return make_pair(1,0);
  }
  else if(x==1){
    return make_pair(1,1);
  }
  else if(x==2){
    return make_pair(0,0);
  }
  else if(x==3){
    return make_pair(0,1);
  }
}

int main(){
  ll N;
  cin >> N;
  ll k;
  vector<int> four;
  vector<int> S;
  if(N==0){
    cout << 0 << endl;
    return 0;
  }
  else if(N>0){
    ll p=1;
    ll l=0;
    while(p<3*N-1){
      p*=4;
      l++;
    }
    k=2*l-1;
    N+=2*(pow(2,k+1)-1)/3;
    for(int i=0;i<=(k-1)/2;i++){
      four.push_back(N%4);
      N/=4;
    }
  }
  else if(N<0){
    ll p=1;
    ll l=0;
    while(2*p<-3*N+2){
      p*=4;
      l++;
    }
    k=2*l;
    N+=2*(pow(2,k)-1)/3;
    for(int i=0;i<=k/2-1;i++){
      four.push_back(N%4);
      N/=4;
    }
  }
  for(int i=(int)four.size()-1;i>=0;--i){
    S.push_back(ftoS(four[i]).first);
    S.push_back(ftoS(four[i]).second);
  }
  bool flag=false;
  for(int x:S){
    if(!flag && x==0){
      continue;
    }
    if(x!=0){
      flag=true;
    }
    cout << x;
  }
  cout << endl;
}