#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 100005;

int main() {
    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;
    set<string> st;
    for (int i = 0; i < n; i++) {
        for (int j = i; (j-i+1) <= k; j++) {
            string tmp = s.substr(i,j-i+1);
            st.insert(tmp);
        }
    } 
    auto itr = st.begin();
    rep(i,k-1) itr++;
    cout << *itr << endl;
}