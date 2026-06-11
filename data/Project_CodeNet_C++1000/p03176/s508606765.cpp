#include<bits/stdc++.h>
#define rep(i,x) for(int i=0; i<x; i++)
typedef long long ll;

using namespace std;

int N;
int h[200002];
ll BIT[200002];

void update(int x, ll value){
  for(; x<=N; x+= x&-x){
    BIT[x] = max(BIT[x], value);
  }
}

ll query(int a){
  ll res = 0;
  for(; a>0; a-= a&-a){
    res = max(res, BIT[a]);
  }
  return res;
}



int main(){
  cin>>N;
  rep(i,N) cin>>h[i];
  rep(i,N){
    ll a;
    cin>>a;

    update(h[i],query(h[i])+a);
  }
  cout<<query(N);  
}
