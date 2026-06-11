#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <ctime>
#include <list>
#include <numeric>
#include <utility>
#include <ctime>
#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/
#define poyo 8000

string s;
int x,y;
vi x_num, y_num;
bool dpx[8005][8005*2],dpy[8005][8005*2];

void DEBUG(){
  cout<<'x'<<endl;
  rep(i,x_num.size()){
    cout<<x_num[i]<<endl;
  }
  cout<<'y'<<endl;
  rep(i,y_num.size()){
    cout<<y_num[i]<<endl;
  }
}

void Compress(){
  bool turn=false;
  int cnt=0;
  rep(i,s.size()){
    if(s[i]=='F'){
      cnt++;
    }else{
      if(!turn)x_num.pb(cnt);
      else y_num.pb(cnt);
      cnt=0;
      turn=(!turn);
    }
  }
  if(cnt){
    if(!turn)x_num.pb(cnt);
    else y_num.pb(cnt);
    cnt=0;
  }
}

bool DP(){
  dpx[0][poyo]=dpy[0][poyo]=true;
  rep(i,x_num.size()){
    REP(j,-8000,8001){
      if(dpx[i][j+poyo]){
	dpx[i+1][j+poyo+x_num[i]]=true;
	if(i!=0)dpx[i+1][j+poyo-x_num[i]]=true;
       	//cout<<i<<" "<<j+x_num[i]<<endl;
	//cout<<i<<" "<<j-x_num[i]<<endl;
      }
    }
  }
  rep(i,y_num.size()){
    //cout<<i<<endl;
    REP(j,-8000,8001){
      if(dpy[i][j+poyo]){
	dpy[i+1][j+poyo+y_num[i]]=true;
	dpy[i+1][j+poyo-y_num[i]]=true;
	//cout<<j+y_num[i]<<endl;
      }
    }
  }
  return (dpx[x_num.size()][x+poyo] && dpy[y_num.size()][y+poyo]);
}

int main(){
  cin>>s;
  cin>>x>>y;
  Compress();
  //DEBUG();
  if(DP())cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
