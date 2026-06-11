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
const ll inf=1ll<<29;
int main(){
      int X,Y,N;
      cin>>X>>Y>>N;
      vector<P> ob;
      rep0(i,N){
            int x,y;
            cin>>x>>y;
            if(x>=y) ob.push_back({x,y});
      }
      sort(ob.begin(),ob.end());
      vector<P> obb;
      int i=0;
      for(auto p:ob){
            int x=p.first;
            int y=p.second;
            if(x>y+i){
                  cout<<x-1<<endl;
                  return 0;
            }
            if(x==y+i){
                  i++;
            }
      }
      cout<<X<<endl;
      return 0;
}
