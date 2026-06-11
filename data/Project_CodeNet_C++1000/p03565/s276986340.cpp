#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using P = pair<int, int>;

int main(){
    string s, t;
    cin >> s >> t;

    bool can = false;
    int index = 0;
    rep(i,(int)s.size()-(int)t.size()+1){
        bool flag = true;
        rep(j,(int)t.size()){
            if (s[i+j] != t[j] && s[i+j] != '?'){
                flag = false;
                break;
            }
        }
        // cout << flag << endl;
        if (flag){
            can = true;
            index = max(index, i);
        }
    }

    rep(i,(int)t.size()) s[i+index] = t[i];

    rep(i,(int)s.size()){
        if (s[i] == '?') s[i] = 'a';
    }

    cout << (can? s : "UNRESTORABLE") << endl;
    return 0;
}
