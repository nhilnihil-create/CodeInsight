
#include <bits/stdc++.h>
#define For(i,n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  long long x[N],y[N],xx[N],yy[N];
  long long mnX,mnY,mxX,mxY;
  long long size;
  For(i,N){
    cin >> x[i] >> y[i];
    xx[i] = x[i],yy[i] = y[i];
  }
  sort(x,x+N);
  sort(y,y+N);
  size = (x[N-1]-x[0])*(y[N-1]-y[0]);
  For(i,N-1) for(int j=i+1; j<N; j++){
    For(k,N-1) for(int l=k+1; l<N; l++){
      int num=0;
      mnX = x[i], mxX = x[j];
      mnY = y[k], mxY = y[l];
      for(int p=0; p<N; p++){
        if(mnX<=xx[p] && xx[p]<=mxX && mnY<=yy[p] && yy[p]<=mxY){
          num++;
        }
        if(num>=K) size = min(size, (mxX-mnX)*(mxY-mnY));
      }
    }
  }
  cout << size << endl;
  return 0;
}
