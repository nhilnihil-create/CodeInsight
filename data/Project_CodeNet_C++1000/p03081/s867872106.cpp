#include<bits/stdc++.h>
#define EM 1000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
LL mod = 1e9+7;
using vint = vector<int>;
using vLL = vector<LL>;
using vvint = vector<vector<int>>;
using vvLL = vector<vector<LL>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<char>    t(Q), d(Q);
    map<char, int>  LR;
    LR['R'] = 1, LR['L'] = -1;
    for(int i = 0;i < Q;i++)    cin >> t[i] >> d[i];
    int ans = N;
    for(int k = 0; k < 2;k++) {
        int l = -1, r = N;
        while (r > l + 1) {
            int mid = (l + r) / 2, m = mid;
            bool f = false;
            for (int i = 0; i < Q; i++) {
                if (m < 0 || m > N - 1) break;
                if (s[m] == t[i]) m += LR[d[i]];
                if ((k == 0 && m == N) || (k == 1 && m == -1)) f = true;
            }
            if(k == 0){
                if(f)   r = mid;
                else    l = mid;
            }else{
                if(f)   l = mid;
                else    r = mid;
            }
        }
        if(k == 0)  ans -= N-r;
        else    ans -= l+1;
    }
    cout << ans << endl;
}