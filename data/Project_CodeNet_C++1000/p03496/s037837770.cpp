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
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(){cout<<fixed<<setprecision(20);
		   /*
           a>0 b>0  a>b ->   a<a+b
           a<0,b<0  a>b ->   a+b<b
           a>0 b<0  a>b ->   ?? 
           最初にabsが最大のものをn-1個に足しておけば、符号が揃うのでは？？
           */
           int n;
           cin>>n;
           int mx=0; 
           int x=-1;
           vin a(n);
           vector<pair<int,int>> ans(0);
           rep(i,0,n){
             cin>>a[i];
             if(abs(a[i])>=abs(mx)){
               x=i;
               mx=a[i];
             }
           }
           int m=0;
           rep(i,0,n){
            if(i==x)continue;
             if(a[x]==0)break;
             a[i]+=a[x];
             m++;
             ans.pb(mp(x+1,i+1));
           }
           if(a[x]>=0){
             rep(i,0,n-1){
               if(a[i]>a[i+1]){
                 m++;
                 ans.pb(mp(i+1,i+2));
                 a[i+1]+=a[i];
               }
             }
           }
           else{
              for(int i=n-2;i>=0;i--){
               if(a[i]>a[i+1]){
                 m++;
                 ans.pb(mp(i+2,i+1));
                 a[i]+=a[i+1];
               }
             }
           }
           cout<<m<<endl;
           rep(i,0,m){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
           }
           
}