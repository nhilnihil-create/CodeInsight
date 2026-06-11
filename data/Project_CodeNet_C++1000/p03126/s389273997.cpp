#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> c(m,0);
    rep(i,n){
        int k;
        cin >> k;
        rep(j,k){
            int a;
            cin >> a;
            c[a-1]++;
        }
    }
    int ans=0;
    rep(i,m){
        if(c[i]==n){
            ans++;
        }
    }
    
    cout << ans;
    
	return 0;
}