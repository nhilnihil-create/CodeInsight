#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

string S;

int main() {
    cin >> S;
    int pref = (S[0] - '0')*10 + (S[1] - '0');
    int suff = (S[2] - '0')*10 + (S[3] - '0');
    if (0 < pref && pref <= 12 && 0 < suff && suff <= 12) {
        cout << "AMBIGUOUS" << endl;
        return 0;
    }
    if (0 < pref && pref <= 12) {
        cout << "MMYY" << endl;
        return 0;
    }
    if (0 < suff && suff <= 12) {
        cout << "YYMM" << endl;
        return 0;
    }
    cout << "NA" << endl; 
}