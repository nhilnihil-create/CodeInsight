#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> l(m),r(m);
    rep(i,m) cin >> l[i] >> r[i];
    int lim=0,rim=100001;
    rep(i,m){
        lim = max(l[i],lim);
        rim = min(r[i],rim);
    }
    cout << max(rim-lim+1,0) << endl;
    return 0;
}