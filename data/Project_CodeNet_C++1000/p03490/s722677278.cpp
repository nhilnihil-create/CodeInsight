#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef long long ll;

const int SMAX = 8000;

int main(){
  string s; cin >> s;
  int fx, fy; cin >> fx >> fy;
  vector<int> cx(SMAX+1), cy(SMAX+1);
  for(int i=0;i<=SMAX;i++){
    cx[i]=0; cy[i]=0;
  }
  int turn=1;
  for(int i=0;i<s.size();i++){
    if(s[i] == 'T') turn++;
    else if(turn %2 == 0){
      cy[turn/2]++;
    }else{
      cx[(turn+1)/2]++;
    }
  }
  int xt = (turn+1)/2, yt = turn/2;
  bool dpx[xt+1][2*SMAX+1], dpy[yt+1][2*SMAX+1];
  for(int i=0;i<=xt;i++){
    for(int j=0;j<=2*SMAX;j++){
      dpx[i][j] = false;
    }
  }
  for(int i=0;i<=yt;i++){
    for(int j=0;j<=2*SMAX;j++){
      dpy[i][j] = false;
    }
  }
  dpx[0][SMAX] = true;
  dpx[1][SMAX+cx[1]] = true;
  for(int i=2;i<=xt;i++){
    for(int j=0;j<=SMAX*2;j++){
      if(j-cx[i] < 0){
        dpx[i][j] = dpx[i-1][j+cx[i]];
      }else if(j+cx[i] > SMAX*2){
        dpx[i][j] = dpx[i-1][j-cx[i]];
      }else{
        dpx[i][j] = (dpx[i-1][j-cx[i]] || dpx[i-1][j+cx[i]]);
      }
    }
  }
  dpy[0][SMAX] = true;
  for(int i=1;i<=yt;i++){
    for(int j=0;j<=SMAX*2;j++){
      if(j-cy[i] < 0) dpy[i][j] = dpy[i-1][j+cy[i]];
      else if(j+cy[i] > SMAX*2) dpy[i][j] = dpy[i-1][j-cy[i]];
      else dpy[i][j] = (dpy[i-1][j-cy[i]] || dpy[i-1][j+cy[i]]);
    }
  }
  if(dpx[xt][fx+SMAX] && dpy[yt][fy+SMAX]) cout << "Yes" << endl;
  else cout << "No" << endl;
}