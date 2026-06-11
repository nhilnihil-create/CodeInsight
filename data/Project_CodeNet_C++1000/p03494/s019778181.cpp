#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n;
        ll a[210];
    cin >> n;
    rep(i,n)cin >> a[i];
    
    int ans = 0;
    int i = 0;
    while(1){
        if(a[i]%2==0)a[i] /= 2;
        else break;
        i++;
        if(i==n){
            i=0;
            ans++;
        }
    }
    
    cout << ans;
    
	return 0;
}