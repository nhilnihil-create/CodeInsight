#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    int n,m;
    cin >> n >> m;

    
    vector<int> x(m);
    rep(i,m) cin >> x[i];
    if(n>=m){
        cout<<0<<endl;
        return 0;
    }
    vector<int> d(m-1);
    ll sum =0;
    sort(x.begin(),x.end());
    rep(i,m-1){
        d[i]=x[i+1]-x[i];
        sum+=d[i];

    }
    //cout<< sum << endl;
    sort(d.begin(),d.end());
    int cnt = 0;
    for(int i=d.size()-1;cnt<n-1;i--){
        sum -= d[i];
        cnt++;
    }
    cout << sum << endl;

    return 0;
}