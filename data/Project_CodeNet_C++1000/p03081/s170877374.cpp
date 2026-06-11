#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    pair<char, char> cmd[Q];
    rep(i, Q){
        char a, b; cin >> a >> b;
        cmd[i] = make_pair(a, b);
    }
    int ng_left, ok_left, ng_right, ok_right;
    ng_left = -1; ok_left = N;
    ng_right = N; ok_right = -1;

    int m = (ng_left+ok_left)/2;
    while(abs(ng_left-ok_left) > 1){
        bool res = true;
        int pos = m;
        rep(i, Q){
            if(cmd[i].first == S[pos]){
                if(cmd[i].second == 'L') pos--;
                else pos++;
                if(pos < 0) res = false;
            }
        }
        if(res) ok_left = m;
        else ng_left = m;
        m = (ng_left+ok_left)/2;
    }

    m = (ng_right+ok_right)/2;
    while(abs(ng_right-ok_right) > 1){
        bool res = true;
        int pos = m;
        rep(i, Q){
            if(cmd[i].first == S[pos]){
                if(cmd[i].second == 'L') pos--;
                else pos++;
                if(pos >= N) res = false;
            }
        }
        if(res) ok_right = m;
        else ng_right = m;
        m = (ng_right+ok_right)/2;
    }

    cout << max(0, ok_right - ng_left) << endl;
    return 0;
}