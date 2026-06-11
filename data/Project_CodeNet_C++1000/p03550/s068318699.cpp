// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    ll z,w,a[n]; cin >> z >> w;
    rep(i,n) cin >> a[i];
    if(n == 1){
        cout << abs(a[0]-w) << endl;
        return 0;
    }
    cout << max(abs(a[n-1]-w), abs(a[n-2]-a[n-1])) << endl;
}
