#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using grid = vector<vector<int>>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = 1<<30;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S;
    cin>>S;
    map<char,bool> m;
    int cnt = 0;
    for(auto x:S) {
        m[x] = true;
        cnt++;
    }
    if(S == "zyxwvutsrqponmlkjihgfedcba") cout<<-1<<endl;
    else if(cnt != 26) {
        rep(i,26){
            char c = 'a' + i;
            if(!m[c]) {
                S+=c;
                break;
            }
        }
        cout<<S<<endl;
    }
    else {
        int p = 0;
        rep(i,25){
            char t = S[25-i];
            char s = S[24-i];
            if(s<t){
                p = 25-i;
                break;
            }
        }
        char ch = '{';
        for(int i = p; i < 26; i++){
            if(S[i]>S[p-1]) chmin(ch,S[i]);
        }
        S[p-1] = ch;
        rep(i,p) cout<<S[i];
        cout<<endl;
    }
}