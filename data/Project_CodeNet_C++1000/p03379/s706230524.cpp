#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>b(n);
    ll med1, med2;
    rep(i, 0, n){
        cin >> a[i];
        b[i] =  a[i]; 
    }
    sort(b.begin(),b.end());
    med1 = b[n/2-1];
    med2 = b[n/2];
    rep(i, 0, n){
        if(a[i] <= med1)cout << med2 <<endl;
        else cout << med1 <<endl;
    }
}