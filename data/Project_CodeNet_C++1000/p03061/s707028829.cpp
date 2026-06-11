#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const int MAX=1<<20;
int N,dat[2*MAX-1];

//初期化
void init(int n){
  N=1;
  while(N<n) N*=2; 
  for(int i=0;i<2*N-1;i++) dat[i]=0;
}

//k番目(0-index)をaに変更
void update(int k,int a){
  k+=N-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=gcd(dat[k*2+1],dat[k*2+2]);
  }
}

//[a,b)なので0-indexならa--,b--;
int query(int a,int b,int k,int l,int r){
  if(r<=a || b<=l) return 0;
  if(a<=l && r<=b) return dat[k];
  int vl=query(a,b,k*2+1,l,(l+r)/2);
  int vr=query(a,b,k*2+2,(l+r)/2,r);
  return gcd(vl,vr);
}

int main(){
  int n;
  cin>>n;
  init(n);
  
  int x;
  rep(i,n){
    cin>>x;
    update(i,x);
  }
  
  int ma=0,tmp;
  rep(i,n){
    tmp=dat[i+N-1];
    update(i,0);
    ma=max(ma,query(0,n,0,0,N));
    update(i,tmp);
  }
  cout<<ma<<endl;
  
  return 0;
}