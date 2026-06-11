#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
const ll inf = 1001001001;
const ll mod = 1000000007;

int main() {
   int n;
   cin >> n;
   vector<int>c(n-1);
   vector<int>s(n-1);
   vector<int>f(n-1);
   vector<int>ans(n);
   rep(i, 0, n-1){
       cin >> c[i] >> s[i] >> f[i];
   }
   rep(i, 0, n-1){
       //iからN番目の時間をans[i]に格納
       ans[i] += c[i]+s[i];
       rep(j, i+1, n-1){
           if(ans[i] >= s[j]){
               int a;
               if((ans[i]-s[j])%f[j] == 0)a=0;
               else a=1;
               ans[i] = s[j]+((ans[i]-s[j])/f[j]+a)*f[j];
            }
            else{
               ans[i] = s[j];
            }
            ans[i] += c[j];
       }
   }
   rep(i, 0, n){
       cout << ans[i] << endl;
   }
}