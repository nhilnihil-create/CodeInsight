//今回実装バグになった所(2箇所)->12行目,45行目

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#define INF 1000000000
using namespace std;
#define int unsigned long long // 手前に動かした
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,N) for(int i=0;i<N;i++)
#define LOOP1(i,N) for(int i=1;i<=N;i++)
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
 
#define MAN 200000
 
int pow(int n,int k){
  int r=1;
  LOOP(i,k)r*=n;
  return r;
}
 
int sqrt(int n){
  LOOP(i,n){
    if(n<i*i*i)return i-1;
  }
  return -1;
}
 
signed main(){
  int N,P;
  cin >> N >> P;
  int res=1;
  if(N==1){
    cout << P << endl;
    return 0;
  }if(N>41 || N>=P){
    cout << 1 << endl;
    return 0;
  }
  for(int i=2,c=P;i*i<=c;i++){ // 条件式変えた、初期値は2
    // cerr << i << ":" << c;
    if(c%i){
      // cerr << "; :(" << endl;
      continue;
    }
    int ipn = pow(i,N);
    if(ipn>1000000000000LL)break;
    // cerr << "; " << ipn << endl;
    while(c%ipn==0){ // 割れる間割り続ける
      c/=ipn;
      res*=i;
    }
  }
  cout << res << endl;
 
}