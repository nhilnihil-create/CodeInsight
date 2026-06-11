#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0;i < n;i++)
#define mrep(p,mp) for(auto p : mp)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
ll a,b,c,k;
cin >> a >> b >> c >> k;
ll ans;
ans = a - b;
if(k % 2 == 1) ans = -ans;
cout << ans << endl;
}