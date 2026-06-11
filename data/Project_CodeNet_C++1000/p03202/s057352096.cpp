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
#define DECIMAL setprecision(17)
#define DEBUG(a) cout<<a<<" "
#define NEWLINE cout<<"\n"
#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false)

  
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<char,P> Q;
ll longinf=(1ll<<60);
const ll inf=1ll<<29;
int main(){
      SPEEDUP;
      ll n;
      cin>>n;
      ll a[n];
      rep0(i,n)cin>>a[i];
    int mochi=0;
  rep0(i,n-1) if(a[i+1]<=a[i]) mochi=1;
  if(!mochi){
    cout<<1<<endl;
    return 0;
  }
      ll ng=1;
      ll ok=200002;
      map<ll,ll> counter;
      while(ok-ng>1){
            bool good=true;
            ll now=(ok+ng)/2;
            map<ll,ll> counter;
            rep0(i,n-1){
                  if(a[i+1]>a[i]) continue;
                  ll j=a[i+1];
                  while(1){
                        if(j<=-1){
                          good=false;
                          break;
                        }
                        if(counter[j]==(now-1)){
                              --j;
                        }
                        else if(counter[j]<now-1){
                          	counter[j]++;
                              counter.erase(counter.lower_bound(j+1),counter.end());
                              break;
                        }
                  }
                  //rep0(i,10) DEBUG(counter[i]);
                  //NEWLINE;
                  }
            if(counter[0]>0) good=false;
                  //NEWLINE;
            if(good) ok=now;
            else ng=now;
      }
      cout<<ok<<endl;
      return 0;
}
