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
		   //左半分を白　右　黒　で塗って置く。必要数だけ点を打っていく。
           int a,b;
           cin>>a>>b;
           a--;b--;
           int h=100,w=100;
           vst ans(h,"");
           rep(i,0,h){
            rep(j,0,w){
             if(j<50){
               ans[i]+='.';
             }
             else{
               ans[i]+='#';
             }
            }
           }
           /////////////
           int num=0;
           int bh=0,bw=0;
           while(b>num){
             ans[bh][bw]='#';
             bh+=2;
             if(bh>=h){
              bh=0;
               bw+=2;
             }
             num++;
           }
           int ah=0,aw=w-1;
           num=0;
           while(a>num){
             ans[ah][aw]='.';
             ah+=2;
             if(ah>=h){
              ah=0;
               aw-=2;
             }
             num++;
           }
           cout<<h<<" "<<w<<endl;
           rep(i,0,h)cout<<ans[i]<<endl;
}