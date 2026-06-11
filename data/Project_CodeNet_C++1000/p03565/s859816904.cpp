#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

int main() {
    string s,t;
    cin >> s >> t;
    int ss = s.size();
    int tt = t.size();
    set<string> A;
    if(ss<tt) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    rep(i,1+ss-tt){
        bool flag = true;
        rep(j,tt){
            if(s[ss-1-i-j]!=t[tt-1-j]&&s[ss-1-i-j]!='?') flag = false;
        }
        if(flag){
            string tmp="";
            rep(j,ss){
                if(s[j]=='?'){
                    tmp += 'a';
                } else {
                    tmp += s[j];
                }
            }
            rep(j,tt){
                tmp[ss-1-i-j] = t[tt-1-j];
            }
            A.insert(tmp);
        }
    }
    auto l = A.begin();
    if(A.empty()) cout << "UNRESTORABLE" << endl;
    else cout << *l << endl;
}