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
		   int a,b,q;
           cin>>a>>b>>q;
           vll s(a);vll t(b);vll x(q);
           rep(i,0,a)cin>>s[i];
           rep(i,0,b)cin>>t[i];
           rep(i,0,q)cin>>x[i];
           map<ll,ll> dists,distt;
           /////////////
           rep(i,0,a){//sからtへの最短距離
             ll n=s[i];
             int l=-1,r=b;
             while(r-l>1){
              int mid=(l+r)/2;
               if(t[mid]<=n)l=mid;
               else r=mid;
             }
             if(l==-1)l++;
             if(r==b)r--;
             dists[n]=min(abs(n-t[l]),abs(n-t[r]));
             
           }
           rep(i,0,b){//t->s
             ll n=t[i];
             int l=-1,r=a;
             while(r-l>1){
              int mid=(l+r)/2;
               if(s[mid]<=n)l=mid;
               else r=mid;
             }
             if(l==-1)l++;
             if(r==a)r--;
             distt[n]=min(abs(n-s[l]),abs(n-s[r]));
             //cout<<i<<" "<<distt[n]<<endl;
           }
           //////////
           rep(i,0,q){
             ll ans=INF;
             ll cnt=0;
             ll n=x[i];
             //
             int l=-1,r=a;
             while(r-l>1){
              int mid=(l+r)/2;
               if(s[mid]<=n)l=mid;
               else r=mid;
             }
             if(l==-1)l++;
             if(r==a)r--;
             cnt+=dists[s[l]];
             cnt+=abs(n-s[l]);
             chmin(ans,cnt);
             cnt=0;
             cnt+=dists[s[r]];
             cnt+=abs(n-s[r]);
             chmin(ans,cnt);
             cnt=0;
             l=-1,r=b;
             while(r-l>1){
              int mid=(l+r)/2;
               if(t[mid]<=n)l=mid;
               else r=mid;
             }
             if(l==-1)l++;
             if(r==b)r--;
             cnt+=distt[t[l]];
             cnt+=abs(n-t[l]);
             chmin(ans,cnt);
             cnt=0;
             cnt+=distt[t[r]];
             cnt+=abs(n-t[r]);
             chmin(ans,cnt);
             cout<<ans<<endl;
           }
}