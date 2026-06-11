#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    vector<int> t(26);
    rep(i,s.size()) t[s[i]-'a']++;
    if(s.size()<26){
        cout << s;
        rep(i,26){
            if(t[i]==0) {
                char ans = 'a'+ i;
                cout << ans << endl;
                return 0;
            }
        }
    }
    else if(s=="zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }
    else{
        string u = s;
        next_permutation(all(u));
        rep(i,s.size()){
            cout << u[i];
            if(s[i]!=u[i]) break;
        }
        cout << endl;
    }

    return 0;
}