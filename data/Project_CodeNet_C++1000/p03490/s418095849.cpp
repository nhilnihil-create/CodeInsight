#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;

#define INF 1 << 30
#define REP(i,n) for(ll i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(ll i=(k);i<(int)(n);i++)




string s;
int x,y;
int d = 0;//0がx,1がy
vector<int> cx;
vector<int> cy;

bool dpx[8001][16010];
bool dpy[8001][16010];

int main(){
  cin >> s>> x>>y;
  int first = 0;
  int t = 0;
  while(t < s.size() && s[t] == 'F'){
    t++;
    first++;
  }
  FOR(i,t,s.size()){
    if(s[i]=='F'){
      int cnt = 0;
      while(i<s.size() && s[i]=='F'){
        cnt++;
        i++;
      }
      i--;
      if(d == 0){
        cx.push_back(cnt);
      }else{
        cy.push_back(cnt);
      }
    }else{
      d = (d+1) % 2;
    }
  }
  dpx[0][8005+first] = true;
  REP(i,cx.size()){
    REP(j,16010){
      if(!dpx[i][j]) continue;
      dpx[i+1][j-cx[i]] = true;
      dpx[i+1][j+cx[i]] = true;
    }
  }
  dpy[0][8005] = true;
  REP(i,cy.size()){
    REP(j,16010){
      if(!dpy[i][j]) continue;
      dpy[i+1][j-cy[i]] = true;
      dpy[i+1][j+cy[i]] = true;
    }
  }
  if(dpx[cx.size()][8005+x] && dpy[cy.size()][8005+y]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
