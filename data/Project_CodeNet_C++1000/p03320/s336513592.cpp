#include "bits/stdc++.h"
using namespace std;

//

#define RESIDUE(u,v) (capacity[u][v] - flow[u][v])
#define RCOST(u,v) (cost[u][v] + h[u] - h[v])
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

LL k;
vector<LL> v;

LL digit(LL a){
  LL ret=0;
  while(1){
    if(a==0)break;
    ret++;
    a/=10;
  }
  return ret;
}

LL sum_digit(LL a){
  LL ret=0;
  while(1){
    if(a==0)break;
    ret+=a%10;
    a/=10;
  }
  return ret;
}

double value(LL a){
  return (double)a/(double)sum_digit(a);
}

int main(){
  cin >> k;
  if(k<=9){
    REP(i,k)
      cout<<i+1<<endl;
    return 0;
  }
  REP(i,9)
    v.push_back(i+1);
  LL plus_digit = 1;
  LL cand = 10;
  while(1){
    //cerr<<cand<<endl;
    double conf = cand/(9*digit(cand));
    if(v.size() >= k && (value(v[k-1])) <= conf)break;
    while(v.size()){
      if(value(v.back()) <= value(cand))break;
      v.pop_back();
    }
    v.push_back(cand);
    if(value(cand) > plus_digit){
      //cerr<<"dbg"<<endl;
      cand += plus_digit*(9-(cand/plus_digit)%10);
      plus_digit*=10;
      continue;
    }
    cand+=plus_digit;
  }
  
  REP(i,k){
    cout<<v[i]<<endl;
  }
  return 0;
}
