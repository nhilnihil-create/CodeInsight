#include <iostream>
#include <cstdio>                                               //scanf,printf
#include <algorithm>                                            //max,min
#include <string>                                               //string
#include <cstring>                                              //strlen,strcat
#include <cctype>                                               //isalpha,tolower
#include <cmath>                                                //sqrt,sin
#include <stack>                                                //top,push
#include <queue>                                                //front,push
#include <vector>                                               //push_back,sort
#include <set>                                                  //insert,begin
#include <map>                                                  //insert,find
#include <list>                                                 //push_front,begin
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>                                               //pow,powf
#define INF 2000000000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define ll long long
#define PL pair<long long, long long>
#define P pair<int,int>
#define mk make_pair
#define en endl;
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define rep(i,n) for(int i=0; i<n; i++)

ll e;
bool C(ll d){
  return e>d*d;
}

int main(){
  ll n,a,b,ans;
  cin>>n;
  rep(i, n){
    ll lb,ub;
    cin>>a>>b;
    if(b>a){ ub=b; lb=a;}
    else {ub=a; lb=b;}
    
    e=a*b;
    rep(i, 100){
      ll mid=(ub+lb)/2;
      if(C(mid)) lb=mid;
      else ub=mid;
    }
    
    if((lb+1)*lb<e) ans=lb*2-1;
    else ans=lb*2-2;
    
    cout<<ans<<en
  }
}
