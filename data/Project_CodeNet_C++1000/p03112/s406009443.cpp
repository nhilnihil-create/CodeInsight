#include <bits/stdc++.h>
using namespace std;
long M=2e10; set<long> S{M}, T{M}, Sm{0}, Tm{0};
long nearestS(long x){
long y=*S.lower_bound(x); long z=*Sm.lower_bound(-x); z=-z;
if(y>1e10){ return x-z; }else if(z<1){ return y-x; }
else{ long w=min(x-z, y-x); return w; }
}
long nearestT(long x){
long y=*T.lower_bound(x); long z=*Tm.lower_bound(-x); z=-z;
if(y>1e10){ return x-z; }else if(z<1){ return y-x; }
else{ long w=min(x-z, y-x); return w; }
}
int main(){
long A, B, Q, i, s, t, x, y, ans; cin >> A >> B >> Q;
for(i=0; i<A; i++){ cin >> s; S.insert(s); Sm.insert(-s); }
for(i=0; i<B; i++){ cin >> t; T.insert(t); Tm.insert(-t); }
for(i=0; i<Q; i++){ cin >> x; ans=M;
y=*S.lower_bound(x); if(y<=1e10){ ans=y-x+nearestT(y); }
y=*Sm.lower_bound(-x); y=-y; if(y>0){ ans=min(ans, x-y+nearestT(y)); }
y=*T.lower_bound(x); if(y<=1e10){ ans=min(ans, y-x+nearestS(y)); }
y=*Tm.lower_bound(-x); y=-y; if(y>0){ ans=min(ans, x-y+nearestS(y)); }                  
cout << ans << "\n";
}
}