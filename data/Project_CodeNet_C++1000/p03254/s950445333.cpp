#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int) n; i++)
#define repb(i, n) for (int i = (int) n; i >= 0; i--)
#define reps(i, m, n) for (int i = (int) m; i < (int) n; i++)
#define repsb(i, m, n) for (int i = (int) m; i >= (int) n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
# define pb(a) push_back(a)
#define ll long long int
const ll LLINF = 1e18 + 10;
int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return 1; } return 0; }
template < class T > bool chmin(T & a,const T & b) { if (b < a) { a = b; return 1; } return 0; }
//vector<vector<int>> vec(n_rows, vector<int>(n_cols, value));
using namespace std;
int main(int argc, char const * argv[]){
    int n,ans;
    cin >> n;
    ll x;
    vector<ll> v(n,-1);
    cin>>x;
    rep(i,n) cin>>v[i];
    VSORT(v);
    ll cnt=0;
    if(v[0]>x){
        cout<<0<<endl;
        return 0;
    }
    rep(i, n)
    {
        cnt+=v[i];
        if(cnt==x){
            ans = i+1;
            break;
        }
        if(cnt>x){
            ans = i;
            break;
        }
        ans = n - 1;
    }
    cout << ans << endl;
    return 0;
}