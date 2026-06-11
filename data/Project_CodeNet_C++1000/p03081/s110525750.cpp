#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

#define SIZE 200005

int n,m;
string str;
char mo[SIZE],dr[SIZE];
int ch[SIZE],d[SIZE];
int i,j,k;

bool left(int p){
  for(i=0;i<m;i++){
    if(str[p]-'A'==ch[i]){
      p+=d[i];
      if(p<0) return true;
      if(p>=n) return false;
    }
  }
  return false;
}

bool right(int p){
  for(i=0;i<m;i++){
    if(str[p]-'A'==ch[i]){
      p+=d[i];
      if(p>=n) return true;
      if(p<0) return false;
    }
  }
  return false;
}

int main(){
  cin>>n>>m;
  cin>>str;
  for(i=0;i<m;i++){
    cin>>mo[i]>>dr[i];
    ch[i]=mo[i]-'A';
    if(dr[i]=='R') d[i]=1;
    else d[i]=-1;
  }

  int ret=n;
  int l=-1,r=n;

  while(r-l>1){
    int d=(r+l)/2;
    if(left(d)) l=d;
    else r=d;
  }

  ret-=r;
  //cout<<ret<<endl;
  l=-1,r=n;

  while(r-l>1){
    int d=(r+l)/2;
    if(right(d)) r=d;
    else l=d;
  }

  ret-=n-r;

  cout<<ret<<endl;
}
