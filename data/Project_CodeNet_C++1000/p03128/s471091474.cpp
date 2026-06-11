#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long int;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1e11;
const ll MOD = 1000000007;
typedef pair<int,int> P;
ll match[10] = {0,2,5,5,4,5,6,3,7,6};
string big(string s,string t){
    string res = "";
    rep(i,s.length()){
        if (s[i]-'0' > t[i]-'0'){
            res = s;
            break;
        }
        else if (s[i]-'0' < t[i]-'0'){
            res = t;
            break;
        }
    }
    if (res == "") res = s;
    return res;
}
int main(){
    ll n,m,a;
    cin >> n >> m;
    ll num[9] = {0};
    rep(i,m){
        cin >> a;
        chmax(num[match[a]],a);
    }
    string s[20005];
    string c;
    ll l;
    s[0] = "";
    rep(i,n){
        l = s[i].length()+1;
        if (i != 0 && s[i] == "") continue;
        rep(j,2,8){
            if (num[j] != 0){
                if (i == 0 || num[j] < s[i][0]-'0'){
                    c = s[i]+(char)(num[j]+'0');
                }
                else c = (char)(num[j]+'0')+s[i];
                //PRINT(i+j << " " << c << " " << s[i+j]);
                if (l > s[i+j].length()) s[i+j] = c;
                else if(l == s[i+j].length()) s[i+j] = big(s[i+j],c);
            }
        }
    }
    PRINT(s[n]);
}