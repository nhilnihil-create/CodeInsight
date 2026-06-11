#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,double> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

int six(int k) {
    if(k==0) return 0;
    int num = 1;
    while(1) {
        if(k < num * 6) break;
        num*=6; 
    }
    int cnt = 0;
    while(1) {
        if(num > k) {
            num/=6;
            continue;
        }
        int ans = k/num;
        cnt += ans;
        k -= ans * num;
        num/=6;
        if(k==0) break;
    }
    return cnt;
}

int nine(int k) {
    if(k==0) return 0;
    int num = 1;
    while(1) {
        if(k < num * 9) break;
        num*=9; 
    }
    int cnt = 0;
    while(1) {
        if(num > k) {
            num/=9;
            continue;
        }
        int ans = k/num;
        cnt += ans;
        k -= ans * num;
        num/=9;
        if(k==0) break;
    }
    return cnt;
}

int main() {
    int n;cin>>n;
    ll ans = 100010;
    rep(i,n+1) {
        ans = min(ans,ll(six(i)+nine(n-i)));
    }
    cout<<ans<<endl;
}