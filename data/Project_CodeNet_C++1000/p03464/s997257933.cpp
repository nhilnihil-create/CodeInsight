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
		   ll k;
           cin>>k;
           vll a(k);
           rep(i,0,k)cin>>a[i];
           if(a[k-1]!=2){
            cout<<-1<<endl;
             return 0;
           }
           ll mn=2,mx=3;
           reverse(all(a));
           rep(i,1,k){
             ll r=a[i];
            if(r>mx){
             cout<<-1<<endl;return 0; 
            }
            if(a[i]>=mn){
             mn=a[i]; 
            }
            else{
               ll g=(mn+a[i]-1)/a[i];
               a[i]=g*a[i];
               mn=a[i];
               if(a[i]>mx){
                cout<<-1<<endl;
                 return 0;
               }
             }
             a[i]=r;
             //mn
             /*while(a[i]+r<=mx)a[i]+=r;
             mx=a[i]+r-1;*/
             ll kk=(mx-a[i])/r;
             a[i]+=kk*r;
             mx=a[i]+r-1;
            //cout<<mx<<endl;
           }
           cout<<mn<<" "<<mx<<endl;
}