#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000007
bool ass[MOD];
int N;
long long ask(long long a){
  int b=0,c=0,d=0;
  while(a>0){
    if(a%10==3) b=1;
    if(a%10==5) c=1;
    if(a%10==7) d=1;
    a=a/10;
  }
  if(b==1){
    if(c==1){
    if(d==1){
    return 1;
    }
    }
  }
  else 
    return 0;
}
void aii(long long a){
  if(ask(a)==1){
    ass[a]=true;
  }
  if(a<MOD/10){
  aii(a*10+3);
  aii(a*10+5);
  aii(a*10+7);
  }
}
int main (){
  int aaa=0;
  cin>>N;
  aii(3);
  aii(5);
  aii(7);
  rep(i,N){
    if(ass[i+1]) aaa++;
  }
  cout<<aaa;
}
