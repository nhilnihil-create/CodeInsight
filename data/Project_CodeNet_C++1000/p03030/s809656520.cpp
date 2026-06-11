//bit全探索
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
 int pp[110];

int main(){cout<<fixed<<setprecision(10);
		   int n;
           cin>>n;
           map<pair<string,int>,int> book;
           string s;
           map<string,int> cnt;
           int p;
           rep(i,0,n){
             cin>>s>>p;
             book[mp(s,p)]=i+1;
             cnt[s]++;
           }
           //sort(all(book));
           int f=0;
          
           for(auto v:book){
             int r=cnt[v.first.first];
             int e=v.second;
            if(r==1){
             cout<<e<<endl; 
              f=0;
            }
             else{
               f++;
               pp[f]=e;
             }
             if(f==r){
               rep(j,0,f){
                cout<<pp[f-j]<<endl; 
               }
               f=0;
             }
           }
}