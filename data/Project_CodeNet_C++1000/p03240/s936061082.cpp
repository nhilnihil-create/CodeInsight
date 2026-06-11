#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef pair<string,string> Pstring;
typedef pair<double,double> Pdouble;


#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define Precision13 cout << fixed << setprecision(13)
const double PI=3.14159265358979323846;
const int MAX = 510000;
const int MOD = 1000000007;
const int INF = 1<<29;
using Graph = vector<vector<int>>;

int main() {

  ll n;
  cin >> n;
  vector<ll> x(n);
  vector<ll> y(n);
  vector<ll> h(n);
 
  REP(i,n) cin >> x[i] >> y[i] >> h[i];

  ll lx=-1,ly=-1,lh=-1;

  REP(i,101){
    REP(j,101){
      bool flag = true;
      ll xh=-1;
      REP(k,n){
        ll cdc= abs(i-x[k])+abs(j-y[k])+h[k];
        if(h[k]!=0){
          if(xh==-1){
            xh = cdc;
          }else{
            if(xh!=cdc){
              flag = false;
            }
          }
        }
      }
      REP(k,n){
        if(h[k]==0){
          ll cdcex=abs(i-x[k])+abs(j-y[k]);
          if(cdcex<xh){
            flag = false;
          }
        }
      }

      if(flag){
        lx = i;
        ly = j;
        lh = xh;
      }
    }
  }

  cout << lx << " " << ly << " " << lh << endl;

}

  
