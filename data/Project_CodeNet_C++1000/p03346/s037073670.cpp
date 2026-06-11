#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), pos(n), ans(n);
    rep(i, n){
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    rep(i, n){
        if(a[i] == 0)ans[0] = 1;
        else{
            if(pos[a[i]-1] < i)ans[a[i]] = ans[a[i]-1]+1;
            else ans[a[i]] = 1;
        }
    }
    cout << n - *max_element(all(ans)) << endl;
}
