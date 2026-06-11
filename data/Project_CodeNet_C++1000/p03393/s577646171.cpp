//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    string S;
    cin >> S;

    int num = S.size();
    vector<bool> check(26);
    rep(i, num) {
        check[S[i]-'a'] = true;
    }

    if(num != 26) {
        cout << S;
        int i;
        rep(i_, num+1) {
            if(!check[i_]) {
                i = i_;
                break;
            }
        }
        char x = 'a'+i;
        cout << x << endl;
    } else {
        for(int i = num-1; i>0; --i) {
            if(S[i] > S[i-1]) {
                string h = S.substr(i);
                reverse(all(h));
                string::iterator itr = lower_bound(all(h), S[i-1]);
                cout << S.substr(0, i-1) << *itr << endl; 
                break;
            }
            if(i == 1) {
                cout << -1 << endl;
            }
        }
    }
}