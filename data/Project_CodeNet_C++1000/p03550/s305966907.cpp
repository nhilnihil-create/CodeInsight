#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int64_t n,z,w;
  cin >> n >> z >> w;
  int64_t k[n];
  rep(i,n)cin >> k[i];
  int64_t y[n];
  int64_t u[n];
  y[0]=0;
  u[0]=0;
  int64_t mi=1000000000000;
  int64_t ma=0;
  rep(i,n-1){
    int q=n-2-i;
    y[q]=max(ma,abs(k[q]-k[n-1]));
    u[q]=min(mi,abs(k[q]-k[n-1]));
    mi=min(mi,y[q]);
    ma=max(ma,u[q]);
  }
  int64_t ans=0;
  rep(i,n-1)ans=max(ans,u[i]);
  cout << max(ans,abs(w-k[n-1])) << endl;
}
