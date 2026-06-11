#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
vin l;
int ans=inf;
int n;
void f(int x,int a,int b,int c,int flag,int p,int q,int r){
 if(flag==0){
   a-=l[x];
   p++;
 }
 else if(flag==1){
   b-=l[x];
   q++;
 }
 else if(flag==2){
   c-=l[x];
   r++;
 }
 
  if(x==n-1){
    int cnt=abs(a)+abs(b)+abs(c);
    if(p==0||q==0||r==0)return;
    if(p>=2)cnt+=10*(p-1);
    if(q>=2)cnt+=10*(q-1);
    if(r>=2)cnt+=10*(r-1);
    //if(cnt==120)cout<<c<<endl;
   chmin(ans,cnt); 
    return ;
  }
 rep(i,0,4){
   f(x+1,a,b,c,i,p,q,r);
 }
}


int main(){cout<<fixed<<setprecision(10);
		   //aに使うか,bに使うか,cに使うか,使わない全探索O(4^n)
           int a,b,c;
           cin>>n>>a>>b>>c;
           l.resize(n);
           rep(i,0,n)cin>>l[i];
           rep(i,0,4)
           f(0,a,b,c,i,0,0,0);
           cout<<ans<<endl;
}