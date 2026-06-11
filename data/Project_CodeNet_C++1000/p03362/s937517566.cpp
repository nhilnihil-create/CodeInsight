#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
   int n;
   cin >> n;
   vector<int>ans;
   rep(i, 2, 55556){
       int p = i;
       vector<int>temp;
       for(int j=1; j*j<=p; j++){
           if(p%j==0){
               temp.push_back(j);
               if(p/j!=j)temp.push_back(p/j);
           }
       }
       if(temp.size() == 2 && p%5 == 1){
           ans.push_back(p);
       }
   }
   rep(i, 0, n)cout << ans[i] << " ";
   cout << endl;
}