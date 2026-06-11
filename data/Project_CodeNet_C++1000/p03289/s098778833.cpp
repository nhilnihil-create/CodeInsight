#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;


int main(){FIN

    string s;cin>>s;
    map<char,ll> mp;
    bool ok = true;
    if (s[0]!='A') ok =false;
    if(count(s.cbegin()+2, s.cend()-1, 'C')!=1) ok = false;
    REP(i,s.size()){
        if (s[i]=='A' || s[i]=='C') {
            mp[s[i]]++;
            if (mp[s[i]]>1) ok = false;
        }
        if (s[i]!='A' && s[i]!='C' && isupper(s[i])) ok = false;
    }
    if (ok) cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
    return 0;
}