#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<char>> g;
int main(){
    string s;   cin >> s;
    vector<ll> key(26, 0);
    REP(i, s.size()){
        key[s[i]-'a'] += 1;
    }
    if(s.size()==26){
        set<char> st;
        st.insert(s.back());
        FORD(i, s.size()-1, 1){
            for(auto x: st){
                if(s[i-1]<x){
                    cout << s.substr(0, i-1) << x << endl;
                    return 0;
                }
            }
            st.insert(s[i-1]);
        }
    }else{
        cout << s;
        REP(i, 26){
            if(key[i]) continue;
            printf("%c\n", i+'a');
            return 0;
        }
    }
    cout << -1 << endl;
}
