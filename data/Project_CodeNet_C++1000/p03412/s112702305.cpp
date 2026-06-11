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
      int maxab=0;
      rep0(i,N) maxab=max(maxab,a[i]);
      rep0(i,N) maxab=max(maxab,b[i]);
      int cnt=0;
      while(maxab>0){
            maxab>>=1;
            cnt++;
      }
      int ans=0;
      for(int k=cnt;k>=0;k--){
            ll hoge = 1ll<<(k+1);
            rep0(i,N) a[i]%=hoge;
            rep0(i,N) b[i]%=hoge;
            sort(b,b+N);
            ll T = 1ll<<k;
            ll piyo=0;
            rep0(i,N){
                  int huga =lower_bound(b,b+N,2*T-a[i])-lower_bound(b,b+N,T-a[i]);
                  int mochi =lower_bound(b,b+N,4*T-a[i])-lower_bound(b,b+N, 3*T-a[i]);
                  piyo+=(huga+mochi);
            }
            int hie=piyo%2;
            ans=2*ans+hie;
      }
      cout<<ans<<endl;

      return 0;
}
