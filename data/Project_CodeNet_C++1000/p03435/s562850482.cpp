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
    vector<vector<int>> c(3, vector<int>(3, 0));

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin >> c.at(i).at(j);
        }
    }

    if(c.at(2).at(0)-c.at(1).at(0)==c.at(2).at(1)-c.at(1).at(1)&&c.at(2).at(1)-c.at(1).at(1)==c.at(2).at(2)-c.at(1).at(2)) {
        ;
    }
    else {
        cout << "No" << endl;
        return 0;
    }
    if(c.at(1).at(0)-c.at(0).at(0)==c.at(1).at(1)-c.at(0).at(1)&&c.at(1).at(1)-c.at(0).at(1)==c.at(1).at(2)-c.at(0).at(2)) {
        ;
    }
    else {
        cout << "No" << endl;
        return 0;
    }
    if(c.at(0).at(0)-c.at(0).at(1)==c.at(1).at(0)-c.at(1).at(1)&&c.at(1).at(0)-c.at(1).at(1)==c.at(2).at(0)-c.at(2).at(1)) {
        ;
    }
    else {
        cout << "No" << endl;
        return 0;
    }
    if(c.at(0).at(1)-c.at(0).at(2)==c.at(1).at(1)-c.at(1).at(2)&&c.at(1).at(1)-c.at(1).at(2)==c.at(2).at(1)-c.at(2).at(2)) {
        ;
    }
    else {
        cout << "No" << endl;
        return 0;
    }
    
    cout << "Yes" << endl;
    return 0;
}
