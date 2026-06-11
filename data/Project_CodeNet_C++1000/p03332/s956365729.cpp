#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> P;
typedef pair<ll,pair<ll,ll> > p;
#define BIG_NUM 2000000000
#define MOD 998244353
#define EPS 0.000000001
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
const int MAX = 510000;

ll fac[MAX],finv[MAX],inv[MAX];
//http://drken1215.hatenablog.com/entry/2018/06/08/210000
//テーブルを作る前処理　O(n)
//pが素数でなくてはならない
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
//二項係数計算
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main(){
    COMinit();
   ll N,A,B;
   ll K,sum=0;
   cin>>N>>A>>B>>K;
   for(ll i=0;i<=N;i++){
       if((K-i*A)%B==0 && (K-i*A)/B<=N){
           int numB=(K-i*A)/B;
           sum+=COM(N,i)*COM(N,numB);
           sum%=MOD;
       }
   }
   cout<<sum<<endl;
}

