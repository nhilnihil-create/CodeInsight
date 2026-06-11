#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const int INF = (1LL<<31)-1;
const int MOD = 1000000007;


int main(){
    int n; cin >> n;
    vector<int> a(n);
    int ma = -1;
    rep(i,n){
        cin >> a[i];
        ma = max(ma,a[i]);
    }
    int r=0, di = INF;
    rep(i,n){
        if(a[i]==ma)continue;
        if(di > abs( (ma/2)-a[i]) ){
            di = abs( (ma/2)-a[i] );
            r = a[i];
        }
    }
    cout << ma << " " << r << endl;
}