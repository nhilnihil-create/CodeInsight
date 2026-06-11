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

int binary(int bina){
    int ans = 0;
    for (int i = 0; bina>0 ; i++)
    {
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return ans;
}

int main(){cout<<fixed<<setprecision(10);
           //bit全探索2^10=1024通り
		   int n;
           cin>>n;
           vector<vin> a(n,vin(10)),b(n,vin(11));
           rep(i,0,n){
            rep(j,0,10)cin>>a[i][j]; 
           }
           rep(i,0,n){
            rep(j,0,11)cin>>b[i][j]; 
           }
           ll ans=-INF;
           for(int bit=1;bit<(1<<10);bit++){
             ll cnt=0;
             rep(j,0,n){
             int c=0;
             
                 for(int i=0;i<10;i++){//時間i
                   if(bit &(1<<i)&&a[j][i]){//店が開いている
                         c++;
                   }
                 }//for i
               cnt+=b[j][c];
             }
             chmax(ans,cnt);
           }//for bit
           cout<<ans<<endl;
}