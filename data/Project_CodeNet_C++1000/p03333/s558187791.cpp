#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 10000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> l(n),r(n);
    rep(i,n){
        cin>>l.at(i)>>r.at(i);
        r.at(i)=-r.at(i);
    }

    sort(all(l),greater<int>());
    sort(all(r),greater<int>());
    int ans=0,sum=0;
    rep(i,n){
        sum+=l.at(i);
        chmax(ans,sum);
        sum+=r.at(i);
        chmax(ans,sum);
    }
    sum=0;
    rep(i,n){
        sum+=r.at(i);
        chmax(ans,sum);
        sum+=l.at(i);
        chmax(ans,sum);
    }
    cout<<ans*2<<endl;

}