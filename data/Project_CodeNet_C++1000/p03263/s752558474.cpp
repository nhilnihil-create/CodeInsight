#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001

using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
using PPI=pair<P,int>;
ll const mod=998244353;
const ll MAX=300000;
using vi=vector<int>;
using vl=vector<ll>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vp=vector<P>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
const int INF=1e9;
const ll LINF=1e18;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}


//////////////////////////////////////
vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main(){
    int h,w;
    cin>>h>>w;
    vvi a(h+1,vi(w+1));
    vector<tuple<int,int,int,int>>ans;
    rep(i,h)rep(j,w)cin>>a[i][j];
    rep(i,h){
        rep(j,w){
            if(a[i][j]%2==1){
                if(i<h-1){
                    a[i][j]--;
                    a[i+1][j]++;
                    ans.emplace_back(i+1,j+1,i+2,j+1);
                }
                else if(j<w-1){
                    a[i][j]--;
                    a[i][j+1]++;
                    ans.emplace_back(i+1,j+1,i+1,j+2);
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    rep(i,(int)ans.size()){
        int a,b,c,d;
        tie(a,b,c,d)=ans[i];
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }

    return 0;
}