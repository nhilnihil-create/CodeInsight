#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  string s;
  int X,Y,x[10000]={},y[10000]={},nx=0,ny=0,I=0,n;
  bool f=0;
  cin>>s>>X>>Y;
  n=s.length();
  for(;I<n;){
    if(s[I++]=='T') break;
    X--;
  }
  for(;I<n;){
    if(s[I++]=='T'){
      if(f) nx++;
      else ny++;
      f=1-f;
    }
    else{
      if(f) x[nx]++;
      else y[ny]++;
    }
  }
  if(f) nx++;
  else ny++;
  bool dpx[8010][16000]={},dpy[8010][16000]={};
  dpx[0][8000]=1;dpy[0][8000]=1;
  fr(i,nx){
    fr(j,16000){
      if(j-x[i]>=0&&dpx[i][j-x[i]]) dpx[i+1][j]=1;
      if(j+x[i]<16000&&dpx[i][j+x[i]]) dpx[i+1][j]=1;
    }
  }
  fr(i,ny){
    fr(j,16000){
      if(j-y[i]>=0&&dpy[i][j-y[i]]) dpy[i+1][j]=1;
      if(j+y[i]<16000&&dpy[i][j+y[i]]) dpy[i+1][j]=1;
    }
  }
  cout<<((dpx[nx][X+8000]&&dpy[ny][Y+8000])?"Yes":"No")<<endl;
}