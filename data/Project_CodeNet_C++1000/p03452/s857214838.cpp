#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;

long long par[2001000];
long long ranks[2001000];
//rootからどれだけ右にあるか
long long diff_weight[2001000]={};

void init(long long n){
  for(long long i=0;i<n;i++){
    par[i]=i;
    ranks[i]=0;
  }
}

long long find(long long x){
  if(par[x]==x){
    return x;
  }else{
    int r=find(par[x]);
		diff_weight[x]+=diff_weight[par[x]];
		return par[x]=r;
  }
}

long long weight(long long x){
  find(x);
  return diff_weight[x];
}

void unite(long long x,long long y,long long dist){
  dist-=weight(y);
  dist+=weight(x);
  x=find(x);
  y=find(y);
  if(x==y){
    return ;
  }
  if(ranks[x]<ranks[y]){
    par[x]=y;
    diff_weight[x]=(-dist);
  }
  else{
    par[y]=x;
    diff_weight[y]=dist;
  }
  if(ranks[x]==ranks[y]){
    ranks[x]++;
  }
}

bool same(long long x,long long y){
  return find(x)==find(y);
}


int main(){
  long long N,M;
  cin>>N>>M;
  bool judge=true;
  long long L,R,D;
  init(200020);
  for(long long i=0;i<M;++i){
    cin>>L>>R>>D;
    if(same(L,R)){
      if(weight(R)-weight(L)!=D){
        judge=false;
        break;
      }
    }
    else{
      unite(L,R,D);
    }
  }
  if(judge){
    cout<<"Yes"<<"\n";
  }
  else{
    cout<<"No"<<"\n";
  }
return 0;
}
