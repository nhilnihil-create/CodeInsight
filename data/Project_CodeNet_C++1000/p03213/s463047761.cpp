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
		   //75=5*5*3 15*5  25*3  75
           //2 4 4    14 4  24 2  74
           //cout<<5*10*3*6*9*4<<endl;
           int n;
           cin>>n;
           map<int,int> cnt;
           rep(i,1,n+1){//iを素因数分解
             int v=i;
             for(int j=2;j*j<=v;j++){
               while(v%j==0){
                 cnt[j]++;
                 v/=j;
               }
             }
             if(v!=1){
              cnt[v]++; 
             }
           }
           /////////////
           vin num(100,0);
           for(auto v:cnt){
             rep(i,0,100){
               if(v.second>=i) num[i]++;
             }
           }
           int ans=0;
           ans+=num[4]*(num[4]-1)/2*(num[2]-2);
           //cout<<num[4]<<endl;
           ans+=num[14]*(num[4]-1);
           ans+=num[24]*(num[2]-1);
           ans+=num[74];
           cout<<ans<<endl;
}