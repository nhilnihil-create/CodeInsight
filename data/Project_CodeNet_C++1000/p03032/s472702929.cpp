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

int main(){cout<<fixed<<setprecision(10);
		   ll n,k;
           cin>>n>>k;
           vll v(n);
           rep(i,0,n)cin>>v[i];
           ll sum=0;
           rep(i,0,n){
            sum+=v[i]; 
           }
           ll cnt=0;
           ll ans=0;
           
           while(k>0){
             
            ll back=min(k,cnt);
             ll f=k;
             ll b=0;
             if(k>=n){
               ll val=sum;
               back+=(k-n);
               vll ss(n);
               ss=v;
               sort(all(ss));
               rep(i,0,n){
                 if(ss[i]<0){
                   val-=ss[i];
                 }
                 else break;
               }
               chmax(ans,val);
             }
             else{
               
               while(f>=0){
                 ll val=0;
                 vll ss(0);
                 rep(i,0,f){
                   val+=v[i];
                   ss.pb(v[i]);
                 }
                 rep(i,0,b){
                  val+=v[n-1-i];
                   ss.pb(v[n-1-i]);
                 }
                 sort(all(ss));
                 rep(i,0,back){
                  if(ss[i]<0){
                   val-=ss[i]; 
                  }
                   else break;
                 }
                 chmax(ans,val);
                 //if(val==3)cout<<f<<" "<<b<<" "<<back<<endl;
                 f--;
                 b++;
               }
             }
             k--;
             cnt++;
           }
           cout<<ans<<endl;
}