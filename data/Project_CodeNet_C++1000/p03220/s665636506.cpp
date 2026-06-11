#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,t,a;
    cin >> n >> t >> a;
    int h[1100];
    int ans;
    double v = INF;
    rep(i,n)cin >> h[i];
    rep(i,n){
        if(v>(double)abs(a-(t-h[i]*0.006))){
            v=(double)abs(a-(t-h[i]*0.006));
            //cout << (double)abs(a-(t-h[i]*0.006)) << endl;
            ans=i+1;
        }
    }
    
    cout << ans;
	return 0;
}