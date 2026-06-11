#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

vector<string> ans;

int main() {
    string s,t;
    cin >> s;
    cin >> t;
    for (int i = 0; i < max(0,(int)s.size()-(int)t.size()+1); ++i) {
        string tmp = s;
        int cnt = 0;
        for (int j = 0; j < t.size(); ++j) {
            if(s[i+j] == t[j] || s[i+j] == '?') tmp[i+j] = t[j],cnt++;
            else break;
        }
        if(cnt == t.size()){
            for (int k = 0; k < tmp.size(); ++k) if(tmp[k] == '?') tmp[k] = 'a';
            ans.push_back(tmp);
        }
    }

    sort(ans.begin(),ans.end());
    if(ans.size() == 0) cout << "UNRESTORABLE" << endl;
    else cout << ans[0] << endl;
    return 0;
}