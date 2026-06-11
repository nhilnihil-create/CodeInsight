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
    llint n;
    cin >> n;

    llint a=0, b=0, c=0, d=0, e=0;
    string s;
    for(int in=0;in<n;in++) {
        cin >> s;
        if(s.at(0)=='M') a++;
        else if(s.at(0)=='A') b++;
        else if(s.at(0)=='R') c++;
        else if(s.at(0)=='C') d++;
        else if(s.at(0)=='H') e++;
        else ;
    }

    llint ans;
    ans = a*b*c + a*b*d + a*b*e + a*c*d + a*c*e + a*d*e + b*c*d + b*c*e + b*d*e + c*d*e;
    cout << ans << endl;
    return 0;
}
