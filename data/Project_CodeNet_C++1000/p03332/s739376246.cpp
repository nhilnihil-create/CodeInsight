#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;
lint p=998244353;
lint pro[300001];

lint pow_mod(lint a,lint b,lint p){
  if(b==0)return 1;
  if(b%2==0){
    lint d=pow_mod(a,b/2,p);
    return (d*d)%p;
  }else{
    return (a*pow_mod(a,b-1,p))%p;
  }
}

//x / a mod p=x * inv_mod(a,p) 
lint inv_mod(lint a,lint p){
  return pow_mod(a,p-2,p);//(a^(p-2))mod p
}

lint nCk(lint n,lint k){
  return (pro[n]*inv_mod((pro[k]*pro[n-k])%p,p))%p;
}

int main(){
  pro[0]=1;
  FOR(i,1,300001){
    pro[i]=pro[i-1]*i;
    pro[i]%=p;
  }
  lint N,A,B,K;
  cin>>N>>A>>B>>K;
  lint ans=0;
  REP(i,N+1){
    if(K<A*i)continue;
    if((K-A*i)%B!=0)continue;
    if((K-A*i)/B>N)continue;
    ans+=nCk(N,i)*nCk(N,(K-A*i)/B);
    ans%=p;
  }
  cout<<ans<<endl;
  return 0;
}
