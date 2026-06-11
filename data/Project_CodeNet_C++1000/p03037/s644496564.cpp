#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int n, m;
cin >> n >> m;
int maxl = 0;
int minr = 1e5 + 5;
for(int i = 0; i< m; i++){
  int l, r;
 cin >> l >> r;
 maxl = max(maxl, l);
 minr = min(minr, r); 
}
int ans;
if(minr >=maxl) ans = minr - maxl +1;
else ans = 0;
cout << ans <<endl;
return 0;
}