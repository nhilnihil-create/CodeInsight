#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n);
    int mi, maxi=-1;
    rep(i,n){
        cin>>a[i];
        if (abs(a[i])>maxi){
            maxi = abs(a[i]);
            mi = i;
        }
    }
    cout<<2*n-2<<endl;
    rep(i,n){
        if (i==mi) continue;
        cout<<(mi+1)<<" "<<(i+1)<<endl;
    }
    if (a[mi]>0){
        rep(i,n-1)
            cout<<(i+1)<<" "<<(i+2)<<endl;
    }else{
        RFOR(i,n-2,0)
            cout<<(i+2)<<" "<<(i+1)<<endl;
    }
    return 0;
}
