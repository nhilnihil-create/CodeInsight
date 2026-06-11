#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define LINT long long

int main(){
  string S;
  int x, y;
  cin>>S>>x>>y;
  int n = S.size();
  bool dpx[2*n+1]={}, dpy[2*n+1]={}; //座標xはdpx[x+n]
  dpx[n]=true, dpy[n]=true;
  vector<int> vx;
  vector<int> vy;
  int work=0, xy=0; //xy=0はx向き，1はy向き
  REP(i, n){
    if(S[i]=='F') ++work;
    else if(work){
      if(!xy)vx.push_back(work);
      else vy.push_back(work);
      work=0;
      xy=1-xy;
    }
    else xy=1-xy;
  }
  if(S[n-1]=='F'){
      if(!xy)vx.push_back(work);
      else vy.push_back(work);
  }

  bool dpw[2*n+1];

  REP(i, vx.size()){
    if(i==0 && S[0]=='F'){
      dpx[n+vx[i]] = true;
      dpx[n] = false;
    }
    else{
      REP(j, 2*n+1){
        if(j-vx[i]>-1) dpw[j] = dpx[j-vx[i]];
        if(j+vx[i]<2*n+1 && !dpw[j]) dpw[j] = dpx[j+vx[i]];
      }
      REP(j, 2*n+1) dpx[j] = dpw[j];
    }
  }
  REP(i, vy.size()){
    REP(j, 2*n+1){
      if(j-vy[i]>-1) dpw[j] = dpy[j-vy[i]];
      if(j+vy[i]<2*n+1 && !dpw[j]) dpw[j] = dpy[j+vy[i]];
    }
    REP(j, 2*n+1) dpy[j] = dpw[j];
  }
  bool ans = dpx[n+x] & dpy[n+y];
  cout<<(ans?"Yes":"No")<<endl;


  return 0;
}
