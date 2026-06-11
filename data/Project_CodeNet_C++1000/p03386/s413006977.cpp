#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
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
    int a, b, k; cin >> a >> b >> k;
    set<int> st;
    for (int i = a; i < a+k && i <= b; i++) {
        st.insert(i);
    }
    for (int i = b; i >= b-k+1 && i >= a; i--) {
        st.insert(i);
    }
    for (auto itr = st.begin(); itr != st.end(); itr++) {
        cout << *itr << endl;
    } 
}