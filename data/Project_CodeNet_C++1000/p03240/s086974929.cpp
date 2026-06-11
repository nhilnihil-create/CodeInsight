#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> x(n),y(n),h(n);
  int vi=1;
  for(int i=0;i<n;++i){
    cin >> x[i] >> y[i] >> h[i];
    if(h[i]>0) vi=i;
  }

  long long cx,cy,ch;
  cx=-1;
  cy=-1;
  ch=-1;
  for(int i=0;i<=100;++i){
    for(int j=0;j<=100;++j){
      long long nh=h[vi]+abs(i-x[vi])+abs(j-y[vi]);
      bool ok=true;
      for(int k=0;k<n;++k){
        if(h[k]>0 && nh-h[k]!=abs(i-x[k])+abs(j-y[k])) ok=false;
        if(h[k]==0 && nh>abs(i-x[k])+abs(j-y[k])) ok=false;
      }
      if(ok){
        cx=i;
        cy=j;
        ch=nh;
      }
    }
  }
  cout << cx << " " << cy << " " << ch << endl;
  return 0;
}
