#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=(1LL<<63) - 600;
const ll mod=1e9+7 ;


int main(){
  int N; string S; int Q; cin >> N >> S >> Q; 
  ll dd=0, mm=0, zenbu=0;
  rep(i, N){
    if(S[i]=='D') dd++;
    if(S[i]=='M') mm+=dd;
    if(S[i]=='C') zenbu+=mm;
  }
  //cout << zenbu << endl;
  rep(i, Q){
    int k; cin >> k; k++; ll cntm[N] = {}; ll cnt=0, ans=0;
    if(S[N-1]=='M'){
      cnt++; cntm[N-1]=1;
    }
    for(int i=N-2; i>=0; i--){
      if(S[i]=='M'){
        cntm[i] = cntm[i+1]+1; cnt++;
      }
      else cntm[i] = cntm[i+1];
    }
    //rep(i, N){
      //if(S[i]=='D') cout << cntm[i] << endl;
    //}
    ll rui[N] = {}; if(S[0]=='D') rui[0] = cntm[0];
    for(int i=1; i<N; i++){
      if(S[i]=='D') rui[i] = rui[i-1]+cntm[i];
      else rui[i] = rui[i-1];
    }
    ll cntd=0;
    for(int i=k-1; i<N; i++){
      if(S[i-k+1]=='D'){
        cntd++;
      }
      if(S[i]=='C'){
        ans+=rui[i-k+1];
        //cout << rui[i-k+1] << " " << i << endl;
        ans-=cntm[i]*cntd;
        //cout << cntm[i] << " " << cntd << endl;
      }
    }
    cout << zenbu-ans << endl;
  }
}