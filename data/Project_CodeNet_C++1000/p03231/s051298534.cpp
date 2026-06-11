#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;  

long long gcn(long long x,long long y){
  if(x%y==0){
    return y;
  }
  else{
    return gcn(y,x%y);
  }
}

int main(void){
  long long res=-1;
  long long n,m;
  long long nn,mm;
  long long g;
  char ss,tt;
  string s,t,tmp;
  long long i,j;
  
  cin>>n>>m;
  cin>>s;
  cin>>t;

  nn=max(n,m);
  mm=min(n,m);
  
  if(m==nn){
    tmp=s;
    s=t;
    t=tmp;
    //cout<<s<<" "<<t<<endl;
  }
  
  g=gcn(nn,mm);
  n=nn/g;
  m=mm/g;

  if(g==1){
    ss=s[0];
    tt=t[0];
    if(ss==tt){
      res=n*m;
    }
    else{
      res=-1;
    }
    cout<<res<<endl;
    return 0;
  }

  
  //cout<<n<<" "<<m<<" "<<g<<endl;
  for(i=0;i<g;i++){
    ss=s[i*n];
    tt=t[i*m];
    //cout<<ss<<" "<<tt<<" "<<(ss==tt)<<endl;
    if(ss!=tt){
      res=-1;
      cout<<res<<endl;
      return 0;
    }
  }
  if(i=g){
    res=n*m*g;
  }
  cout<<res<<endl;
  return 0;
}