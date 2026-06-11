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
		   ll x,y,z,K;
           cin>>x>>y>>z>>K;
           vll a(x),b(y),c(z);
           rep(i,0,x)cin>>a[i];rep(i,0,y)cin>>b[i];rep(i,0,z)cin>>c[i];
           sort(all(a)); sort(all(b)); sort(all(c));
           reverse(all(a));reverse(all(b));reverse(all(c));
           priority_queue<ll, vector<ll>, greater<ll>> pq;
           ll mn=inf;
           ll cnt=0;
           rep(i,0,x){
			rep(j,0,y){
             rep(k,0,z){
               cnt++;
               if(cnt<=3000){
                pq.push(a[i]+b[j]+c[k]);
                mn=pq.top();
               }
               else{
                if(a[i]+b[j]+c[k]>mn){
                  pq.push(a[i]+b[j]+c[k]);
                  pq.pop();
                  mn=pq.top();
                }
                 else{
                  break; 
                 }
               }
             }
            }
           }
           while(pq.size()>K)pq.pop();
           vll ans(K);
           rep(i,0,K){
            ans[K-i-1]=pq.top();
             pq.pop();
             
           }
           rep(i,0,K){
            cout<<ans[i]<<endl; 
           }
}