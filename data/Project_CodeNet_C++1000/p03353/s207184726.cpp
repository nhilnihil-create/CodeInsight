#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
const char newl = '\n';
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL<<60;

int main(){
    string s;cin >> s;
    int k;cin >> k;
    vector<string> st;
    for(int i=0;i<s.size();i++){
        for(int j=1;j<=k;j++){
            st.emplace_back(s.substr(i,j));
        }
    }
    sort(st.begin(),st.end());
    st.erase(unique(st.begin(),st.end()),st.end());
    cout << st[k-1] << endl;
}