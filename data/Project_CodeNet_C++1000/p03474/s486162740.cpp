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
    int a, b;
    cin >> a >> b;

    string s;
    cin >> s;

    if(s.size()!=a+b+1) {
        cout << "No" << endl;
        return 0;
    }

    for(int in=0;in<s.size();in++) {
        if(in==a) {
            if(s.at(in)!='-') { 
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            if(s.at(in)>='0'&&s.at(in)<='9') { 
                ;
            }
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
