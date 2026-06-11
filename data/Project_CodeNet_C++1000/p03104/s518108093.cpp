#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


int main(){cout<<fixed<<setprecision(10);
          ll a,b;
           cin>>a>>b;
           ll cnt[42];
           rep(i,0,42){
             cnt[i]=0;
           }
           if(a%4==2||a%4==3){
             if(b%4==0||b%4==3)cnt[0]++;
           }
           else if(a%4==0||a%4==1){
             if(b%4==1||b%4==2)cnt[0]++;
           }
           rep(i,1,42){//下からi桁目
             if((a/(ll(pow(2,i))))%2){
               cnt[i]+=a% ll(pow(2,i));
               cnt[i]%=2;
               //if(i==0)cout<<cnt[i]<<endl;
             }
           }
                rep(i,1,42){//下からi桁目
             if((b/(ll(pow(2,i))))%2){
               cnt[i]+=b% ll(pow(2,i)) +1;
               cnt[i]%=2;
               if(i==0)cout<<cnt[i]<<endl;
             }
           }
           ll ans=0;
                rep(i,0,42){
                 if(cnt[i])ans+=pow(2,i); 
                }
           cout<<ans<<endl;
}