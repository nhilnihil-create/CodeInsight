#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n, a, b, cnt=0;
     cin >> n >> a >> b;

     for(int i=1; i<=n; i++){
         int s=0;
         int tmp = i;
         while(tmp>0){
             s+=tmp%10;
             tmp/=10;
         }
         if(a<=s && s<=b){
             cnt+=i;
         }
     }
    out(cnt);
}