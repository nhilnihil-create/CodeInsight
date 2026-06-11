#include <bits/stdc++.h>
using namespace std;

int MAX_N=262144;
vector<int64_t> seg(MAX_N*2-1,1);
int64_t qu(int a,int b,int k,int l, int r){
  if(r<=a||b<=l){
    return 0;
  }
  else if(a<=l&&r<=b){
    return seg[k];
  }
  else{
    int64_t X=qu(a,b,k*2+1,l,(l+r)/2);
    int64_t Y=qu(a,b,k*2+2,(l+r)/2,r);
    if(X==0){
      return Y;
    }
    else if(Y==0){
      return X;
    }
    else{
      return gcd(X,Y);
    }
  }
}

int main() {
  int N;
  cin>>N;
  int64_t Z=1;
  for(int i=0;i<N;i++){
    cin>>seg[MAX_N-1+i];
  }
  for(int i=MAX_N-2;i>=0;i--){
    seg[i]=gcd(seg[i*2+1],seg[i*2+2]);
  }
  for(int i=0;i<N;i++){
    int64_t A,B;
    A=qu(0,i,0,0,MAX_N);
    B=qu(i+1,N,0,0,MAX_N);
    if(i==0){
      A=B;
    }
    else if(i!=N-1){
      A=gcd(A,B);
    }
    Z=max(Z,A);
  }
  cout<<Z<<endl;
  
}