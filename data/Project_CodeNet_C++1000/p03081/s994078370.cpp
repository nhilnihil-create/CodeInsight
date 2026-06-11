#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000

int main(){
    ll n, q; cin >> n >> q; string s; cin >> s;
    vector<vector<char>> ql(q,vector<char>(2));
    ll left = -1; ll right = n;
    REP(i,q) cin >> ql[i][0] >> ql[i][1];
    FORD(i,q-1,0){
        if (left!=-1&&s[left]==ql[i][0]&&ql[i][1]=='R') left--;
        if (right!=n&&s[right]==ql[i][0]&&ql[i][1]=='L') right++;
        if (left!=n-1&&s[left+1]==ql[i][0]&&ql[i][1]=='L') left++;
        if (right!=0&&s[right-1]==ql[i][0]&&ql[i][1]=='R') right--;
    }
    ll lim = 0;
    cout << max(lim,right-left-1) << endl;
}