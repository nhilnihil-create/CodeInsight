#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,x;
    cin >> n >> x;
    int m[n];
    int ans=n;
    int minv = 10000000;
    rep(i,n){
        cin >> m[i];
        x-=m[i];
        minv = min(minv,m[i]);
    }
    
    cout << n + x/minv;
    
	return 0;
}