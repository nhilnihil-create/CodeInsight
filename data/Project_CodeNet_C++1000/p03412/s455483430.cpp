#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(10)
 
typedef long long ll;
typedef pair<int,int> P;
ll longinf=1ll<<60;
int inf=1<<29;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int N;
int a[200001],b[200001];


int main (){
      cin>>N;
      rep0(i,N) cin>>a[i];
      rep0(i,N) cin>>b[i];
      int ans=0;
      for(int k=28;k>=0;k--){
            int hoge = 1<<(k+1);
            rep0(i,N) a[i]%=hoge;
            rep0(i,N) b[i]%=hoge;
            sort(b,b+N);
            int T = 1<<k;
            ll piyo=0;
            rep0(i,N){
                  ll huga=lower_bound(b,b+N,2*T-a[i])-lower_bound(b,b+N,T-a[i]);
                  ll mochi=lower_bound(b,b+N,4*T-a[i])-lower_bound(b,b+N, 3*T-a[i]);
                  piyo+=(huga+mochi);
            }
            ans=2*ans+(piyo%2);
      }
      cout<<ans<<endl;

      return 0;
}
