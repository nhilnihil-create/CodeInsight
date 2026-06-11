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
    cin >> n;
    int p[n];
    rep(i,n)cin >> p[i];
    int max=0,ans=0;
    
    rep(i,n){
        ans+=p[i];
        if(p[i]>max)max=p[i];
    }
    
    cout << ans - max/2;
    
	return 0;
}