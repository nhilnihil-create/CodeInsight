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
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll sum=0;
    map<string,ll> left;
    map<string,ll> right;
    rep(bi,bit(n)){
        string l,r;
        string ll,rr;
        rep(i,n){
            if(bi&bit(i)){
                l.pb(s[i]);
                r.pb(s[2*n-i-1]);
                //ll.pb('.');
                //rr.pb('.');
            }
            else{
                //l.pb('.');
                //r.pb('.');
                ll.pb(s[i]);
                rr.pb(s[2*n-i-1]);
            }
        }
      	l+='&';
      	r+='&';
        l+=ll;
        r+=rr;
        left[l]++;
        right[r]++;
    }
  	//for(auto x:right)cerr << x.F << endl;
  	//cerr << endl;
    for(auto x:left){
        sum+=x.S*right[x.F];
        //cerr << x.F << ' ' << x.S << ' ' << right[x.F] << endl;
    }
    cout << sum;

}

/*



 */

