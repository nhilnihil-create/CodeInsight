//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    string S,T; cin >> S >> T;
    vector<string> ans;
    if(S.size() < T.size()) cout << "UNRESTORABLE" << endl;
    else {
        for(int i = 0; i <= S.size()-T.size(); i++) {
            string S_ = S;
            int count = 0;
            //cout << S_ << endl;
            for(int j = 0; j < T.size(); j++) {
                if(S_.at(i+j) == '?') S_.at(i+j) = T.at(j);
                else if(S_.at(i+j) != T.at(j)) break;
                count++;
            }
            if(count == T.size()) {
                for(int i = 0; i < S.size(); i++) if(S_.at(i) == '?') S_.at(i) = 'a';
                ans.push_back(S_);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size() == 0) cout << "UNRESTORABLE" << endl;
        else cout << ans.at(0) << endl;
    }
}

