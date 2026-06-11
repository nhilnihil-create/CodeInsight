#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const double PI=3.141592653589;
const int INF=1000000007;
const ll LMAX=1000000000000001;
int gcd(int a,int b){if(a<b)swap(a,b);int c=a%b;while(c!=0){a=b;b=c;c=a%b;}return b;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


int main(){
  int n; cin>>n;
  vector<int> x(n);
  vector<int> y(n);
  vector<int> h(n);
  rep(i,n) cin>>x[i]>>y[i]>>h[i];

  rep(i,101){
    rep(j,101){
      ll H=-1;
      ll underh=LMAX;
      bool f=1;
      rep(k,n){
        if(k==0){
          if(h[k]==0) underh=abs(x[k]-i)+abs(y[k]-j);
          else H=h[k]+abs(x[k]-i)+abs(y[k]-j);
        }else{
          ll nh=h[k]+abs(x[k]-i)+abs(y[k]-j);
          if(h[k]==0) underh=min(underh,nh-h[k]);
          else{
            if(H==-1) H=nh;
            else if(H!=nh) f=0;
          }
          if(H>underh) f=0;
        }
      }
      if(f&&H>0){
        cout<<i<<" "<<j<<" "<<H;
        return 0;
      }
    }
  }

  return 0;
}
