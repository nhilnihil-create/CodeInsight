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
    int n;
    cin >> n;
    vector<P>x(n+1);
    rep(i,n){
        int a;
        cin >> x[i+1].first;
        x[i+1].second =i+1;
        
    }
    vector<P> a=x;
    sort(x.begin(),x.end());
    int mid = n/2;
    rep(i,n)
    {
        if(a[i+1].first<=x[mid].first)cout<<x[mid+1].first<<endl;
        else cout<<x[mid].first<<endl;
    }
    return 0;
}