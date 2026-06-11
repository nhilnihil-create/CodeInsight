#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int px[90005],py[90005];
int d[90005];
int main(){
    int h,w,D;cin >> h >> w >> D;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int a;cin >> a;
            px[a]=i;
            py[a]=j;
        }
    }
    for(int i=D+1;i<=h*w;i++){
        d[i]=d[i-D]+abs(px[i]-px[i-D])+abs(py[i]-py[i-D]);
    }
    int q;cin >> q;
    for(int i=0;i<q;i++){
        int l,r;cin >> l >> r;
        cout << d[r]-d[l] << endl;
    }
    return 0;
}