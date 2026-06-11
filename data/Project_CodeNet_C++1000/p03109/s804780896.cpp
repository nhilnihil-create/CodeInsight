#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL MOD = 1e9+7;

int main() {
    string s;
    cin >> s;
    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(5, 2));
    int d = stoi(s.substr(8, 2));
    if(2019 < y) {
        cout << "TBD" << endl;
    }else if(4 < m) {
        cout << "TBD" << endl;
    }else{
        cout << "Heisei" << endl;
    }
    return 0;
}
