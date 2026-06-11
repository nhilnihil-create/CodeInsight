#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 10e9+7;
ll mod2 = 998244353;

int main(){
	int n,m;cin>>n>>m;
    vector<int> a(n);
    rep(i,0,m){
        int l,r;cin>>l>>r;
        a[l-1]++;
        if (r<n) a[r]--;
    }
    vector<int> b(n);
    b[0] = a[0];
    rep(i,1,n) b[i] = b[i-1]+a[i];
    int ans = 0;
    rep(i,0,n){
        if (b[i]==m){
            ans++;
        }
    }
    cout<<ans<<endl;
}