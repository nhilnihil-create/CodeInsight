#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int a[110],n,ans=0;
    cin >> n;
    rep(i,n)cin >> a[i];
    sort(a,a+n,greater<int>());
    rep(i,n)ans+=a[i]*pow(-1,i);
    cout << ans;
    
	return 0;
}