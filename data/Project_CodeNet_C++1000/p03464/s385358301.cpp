#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

int main() {
    int k;
    cin >> k;
    ll a[k];
    rep(i,k)cin >> a[i];
    ll mnn=2;
    ll mxn=2;
    rep(i,k){
        if(((mnn-1)/a[k-i-1]+1)*a[k-i-1]>mxn){
            cout << -1;
            return 0;
        }
        mnn=((mnn-1)/a[k-i-1]+1)*a[k-i-1];
        mxn=(mxn/a[k-i-1]+1)*a[k-i-1]-1;
      	//cerr << mnn << mxn << endl;
    }
    cout << mnn << ' ' << mxn;
}