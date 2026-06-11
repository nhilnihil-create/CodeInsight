#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int n;
ll a[200010];
vector<ll> S;
int d1[200010],d2[200010];

void solve(){
    cin >> n;
    S.resize(n+1);
    rep(i,n){
        cin >> a[i];
        S[i+1]=S[i]+a[i];
    }
    int j=0;
    rep(i,n+1){
        while(abs(2ll*S[j]-S[i])>abs(2ll*S[j+1]-S[i])){
            j++;
        }
        d1[i]=j;
        //cout << j << endl;
    }
    j=n;
    per(i,n+1){
        while(abs(S[n]+S[i]-2ll*S[j])>abs(S[n]+S[i]-2ll*S[j-1])){
            j--;
        }
        d2[i]=j;
        //cout << j << endl;
    }
    // rep(i,n+1){
    //     cout << d1[i] << " " << d2[i] << endl;
    // }
    ll ans=INF;
    Rep(k,2,n-1){
        int j1=d1[k],j2=d2[k];
        ll A=S[j1];
        ll B=S[k]-S[j1];
        ll C=S[j2]-S[k];
        ll D=S[n]-S[j2];
        //cout << A << " " << B << " " << C << " " << D << endl;
        ans=min(ans,max(max(A,B),max(C,D))-min(min(A,B),min(C,D)));
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}