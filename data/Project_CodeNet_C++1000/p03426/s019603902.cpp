#include <bits/stdc++.h>
using namespace std;

int main() {
  long H,W,D;
  cin>>H>>W>>D;
  vector<long> px(H*W+1);
  vector<long> py(H*W+1);
  for(int i=0;i<H;i++) for(int j=0;j<W;j++){
    int a;
    cin>>a;
    px[a]=i,py[a]=j;
  }
  vector<long> d(H*W+1);
  for(int i=1;i<=H*W-D;i++){
    d[i+D]=d[i]+abs(px[i+D]-px[i])+abs(py[i+D]-py[i]);
  }
  int Q;
  cin>>Q;
  for(int i=0;i<Q;i++){
    int l,r;
    cin>>l>>r;
    cout<<d[r]-d[l]<<endl;
  }
}
