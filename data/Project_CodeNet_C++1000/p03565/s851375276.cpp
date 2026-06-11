#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

string S, T;
vector<string> v;
 
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> S >> T;
    rep(i,0,S.size()-T.size()+1) {
        bool flag = true;
        rep(j,0,T.size()) {
            if (S[i+j]=='?') continue;
            else flag &= S[i+j]==T[j];
        }
        if (flag) {
            string s = "";
            rep(j,0,S.size()) {
                if (i<=j && j<i+T.size()) s += T[j-i];
                else {
                    if (S[j]=='?') s += "a";
                    else s += S[j];
                }
            }
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end());
    if (v.size()==0) cout << "UNRESTORABLE" << endl;
    else cout << v[0] << endl;
    return 0;
}