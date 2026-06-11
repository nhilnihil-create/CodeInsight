#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
int main()
{
    string s;
    cin >> s;
    queue<char>q;
    rep(i, s.size()) {
        q.push(s[i]);
    }
    string t;
    while (q.size()>1) {
        char a=q.front();q.pop();
        char b=q.front();
        if (a=='B'&&b=='C') {
            t.push_back('D');
            q.pop();
        }
        else {
            t.push_back(a);
        }
    }
    ll co=0;
    ll ans=0;
    rep(i, t.size()) {
        if (t[i]=='B'||t[i]=='C') {
            co=0;
        }
        else if (t[i]=='D') {
            ans+=co;
        }
        else {
            co++;
        }
    }
    cout<<ans<<endl;
}