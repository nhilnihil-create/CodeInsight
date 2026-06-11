#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
#define debug(x) cerr << x << endl
#define Complex complex<double>
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
  	k--;
    int n=s.length();
    set<string> vec;
    rep(i,n){
        rep(j,5){
            if(i+j>=n)break;
            string t="";
            rep(h,j+1){
                t.pb(s[i+h]);
            }
            vec.insert(t);
        }
    }
    vector<string> v;
    for(auto t:vec)v.pb(t);
    sort(all(v));
    cout << v[k];
}