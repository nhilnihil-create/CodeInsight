#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

ll a[2005];

int main(){
    ll n,z,w;
    cin >> n>>z>>w;
    rep(i,n){
        cin >> a[i];
    }
    cerr<<abs(a[n-1]-w)<<' '<<abs(a[n-2]-a[n-1]);
    ll ans=max(abs(a[n-1]-w),abs(a[n-2]-a[n-1]));
    if(n==1){
        ans=abs(a[0]-w);
    }
    cout<<ans<<endl;
    return 0;
}