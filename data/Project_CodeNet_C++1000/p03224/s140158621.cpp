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
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;
//ll longinf=1ll<<60;
int inf=1<<29;
int dh[4]={1,0,-1,0};
int dw[4]={0,1,0,-1};
ll longinf=(1ll<<31)-1;

int main(){
      int n;
      cin>>n;
      int k=0;
      REP(i,2,2000){
            if(n==(i*(i-1))/2){
                  k=i;
            }
      }
      if(k==0){
            cout<<"No"<<endl;
            return 0;
      }
      cout<<"Yes"<<endl;
      int d[k][k];
      rep0(i,k) d[i][i]=0;
      int cnt=1;
      rep0(i,k){
            for(int j=(i+1);j<k;j++){
                  d[i][j]=d[j][i]=cnt;
                  cnt++;
            }
      }
      /*rep0(i,k){
            rep0(j,k){
                  cout<<d[i][j]<<" ";
            }
            cout<<endl;
      }*/
      cout<<k<<endl;
      rep0(i,k){
            cout<<k-1<<" ";
            rep0(j,k){
                  if(d[i][j]) cout<<d[i][j]<<" ";
            }
            cout<<endl;
      }
      return 0;
}