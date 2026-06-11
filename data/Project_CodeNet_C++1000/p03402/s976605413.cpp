#include <bits/stdc++.h>  // ver2.2.8
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define COUNT(a,k) upper_bound(ALL(a),k)-lower_bound(ALL(a),k)
#define BIGGER(a,k) a.end()-upper_bound(ALL(a),k)
#define SMALLER(a,k) lower_bound(ALL(a),k)-a.begin()
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Pii pair<int,int>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl
#define _ <<' '<<
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define Vout(a) rep(lZ,0,a.size()-1)cout<<a[lZ]<<' ';cout<<a.back()<<endl
#define VVout(a) rep(lY,0,a.size()){if(!a[lY].empty()){Vout(a[lY]);}else cout<<endl;}
#define VPout(a) rep(lX,0,a.size())cout<<a[lX].FI<<' '<<a[lX].SE<<endl
#define Verr(a) rep(iZ,0,a.size()-1)cerr<<a[iZ]<<' ';cerr<<a.back()<<endl
#define VVerr(a) rep(J,0,a.size()){if(!a[J].empty()){Verr(a[J]);}else cerr<<'.'<<endl;}
#define VPerr(a) rep(iX,0,a.size())cerr<<a[iX].FI<<' '<<a[iX].SE<<endl
#define INF 3000000000000000000  //  3.0*10^18(MAXの1/3くらい)
#define MAX LLONG_MAX
#define MOD 1000000007  //  10^9 + 7
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm
void press(auto &v){v.erase(unique(ALL(v)),v.end());}  //  圧縮
int mypow(int x, int n, int m){  //  累乗x^n(mod m)  O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}



signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  int w,b;
  cin >> w >> b;
  if(w==1&&b==1) {cout<<"1 2"<<endl<<".#"<<endl;return 0;}
  cout<<"100 100"<<endl;
  vector<string> ans;
  
  string white="";
  string black="";
  
  rep(i,0,100){
    white.pb('.');
    black.pb('#');
  }
  
  int ct=0;
  
  if(w==1){
    rep(i,0,100) ans.pb(white);
    
    rep(i,0,50){
      rep(j,0,50){
        if(ct==b) {
          rep(QW,0,100){
            cout<<ans[QW]<<endl;
          }
          return 0;
        }
        ans[i*2][j*2] = '#';
        ct++;
      }
    }
  }
  if(b==1){
    rep(i,0,100) ans.pb(black);
    
    rep(i,0,50){
      rep(j,0,50){
        if(ct==w) {
          rep(QW,0,100){
            cout<<ans[QW]<<endl;
          }
          return 0;
        }
        ans[i*2][j*2] = '.';
        ct++;
      }
    }
  }
  
  rep(i,0,50){
    ans.pb(white);
  }
  rep(i,0,50){
    ans.pb(black);
  }
  ct = 0;
  bool ok = false;
  rep(i,0,50){
    rep(j,0,50){
      if(ct==b-1) {ok=true;break;}
      ans[i*2][j*2] = '#';
      ct++;
    }
    if(ok) break;
  }
  
  reverse(ALL(ans));
  
  ct=0;
  ok=false;
  
  rep(i,0,50){
    rep(j,0,50){
      if(ct==w-1) {ok=true;break;}
      ans[i*2][j*2] = '.';
      ct++;
    }
    if(ok) break;
  }
  
  
  rep(i,0,100){
    cout << ans[i] << endl;
  }
  return 0;
}