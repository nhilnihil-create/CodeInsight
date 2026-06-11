#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

ll m, a, r, c, h;

int main(void)
{
    ll n, cnt=0;
    cin >> n;
    set<string> st;
    string a="MARCH";
    rep(i,n){
        string s;
        cin >> s;
        rep(j,5) if(s[0] == a[j]) st.insert(s);
    }
    vector<ll> v(5,0);
    for(auto s:st){
        rep(i,5) v[i] += s[0]==a[i];
    }
    rep(i,5)REP(j,i+1,5)REP(k,j+1,5){
        cnt += v[i]*v[j]*v[k];
    }
    cout << cnt << endl;
    return 0;
}
