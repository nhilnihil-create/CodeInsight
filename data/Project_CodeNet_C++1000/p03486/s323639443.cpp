#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    bool flg = false;

    if(s.size()<t.size()) {
        for(int in=0;in<s.size();in++) {
            if(s.at(in)==t.at(in)) ;
            else break;
            if(in==s.size()-1) {
                flg = true;
            }
        }
    }

    for(int in=0;in<min(s.size(), t.size());in++) {
        if(s.at(in)==t.at(in)) continue;
        else if(s.at(in)<t.at(in)) { 
            flg = true;
        }
        else { 
            ;
        }
    }
    
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
