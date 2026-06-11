#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<bitset>
#include<random>
#include<cstdint>
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
#define shosu setprecision(17)
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<char,P> Q;
ll longinf=(1ll<<60);
ll inf=1<<21;
int main(){
      ll N;
      string s;
      ll q;
      cin>>N>>s>>q;
      rep0(ijfijeij,q){
            ll k;
            cin>>k;
            ll cntD=0;
            ll cntM=0;
            ll cntDM=0;
            ll ans=0;
            rep0(i,N){
                  if(s[i]=='D') cntD++;
                  if(s[i]=='M'){
                        cntM++;
                        cntDM+=cntD;
                  }
                  if(i>=k){
                        if(s[i-k]=='M'){
                              cntM--;
                        }
                        if(s[i-k]=='D'){
                              cntDM-=cntM;
                              cntD--;
                        }
                  }
                  if(s[i]=='C'){
                        ans+=cntDM;
                  }
            }
            cout<<ans<<endl;
      }

      return 0;
}