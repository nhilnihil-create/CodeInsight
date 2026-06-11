#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp(a,b) std::make_pair(a,b)
using std::cin;
using std::min;
using std::max;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
int N;
double t[110],v[110];
double vmax[110];//t[i]の時点で出して良い最高速度
double v0[110];//実際にt[i]の時点で出している速度
double solve(){
  double res=0;
  //vmaxの計算
  vmax[N-1]=0;
  for(int i=N-1;i>0;i--){
    vmax[i-1]=min(v[i],t[i]+vmax[i]);
  }
  if(t[0]<=min(v[0],vmax[0])){//vにもvmaxにも到達できない場合
    v0[0]=t[0];
    res+=t[0]*t[0]/2;
  }
  else{
    if(v[0]<=vmax[0]){//vmaxの前にvで頭打ちになる場合
      v0[0]=v[0];
      res+=v[0]*t[0]-v[0]*v[0]/2;
    }
    else{
      if(t[0]+vmax[0]<=2*v[0]){//頭打ちにならず三角形になる場合
	v0[0]=vmax[0];
	res+=(t[0]+vmax[0])*(t[0]+vmax[0])/4-vmax[0]*vmax[0]/2;
      }
      else{//頭打ちになって台形になる場合
	v0[0]=vmax[0];
	res+=(t[0]+vmax[0])*(t[0]+vmax[0])/4-vmax[0]*vmax[0]/2-((t[0]+vmax[0])/2-v[0])*((t[0]+vmax[0])/2-v[0]);	
      }
    }
  }
  rep1(i,N-1){
    double x=t[i],y=std::fabs(vmax[i]-v0[i-1]),z=(x+y)/2,w=v[i]-min(v0[i-1],vmax[i]);
    if(x+v0[i-1]<=min(v[i],vmax[i])){//vにもvmaxにも到達できない場合
      v0[i]=x+v0[i-1];
      res+=min(v0[i-1],v0[i])*x+x*x/2;
    }
    else{
      if(v[i]<=vmax[i]){//vmaxの前にvで頭打ちになる場合
	v0[i]=v[i];
	res+=v[i]*x-w*w/2;
      }
      else{
	if(z<=w){//頭打ちにならず三角形になる場合
	  v0[i]=vmax[i];
	  res+=min(v0[i-1],v0[i])*x+z*z-y*y/2;
	}
	else{//頭打ちになって台形になる場合
	  v0[i]=vmax[i];
	  res+=min(v0[i-1],v0[i])*x+z*z-y*y/2-(z-w)*(z-w);
	}
      }
    }
  }
  return res;
}
int main(){
  cin>>N;
  rep(i,N) cin>>t[i];
  rep(i,N) cin>>v[i];  
  printf("%.4f\n",solve());
  return 0;
}
