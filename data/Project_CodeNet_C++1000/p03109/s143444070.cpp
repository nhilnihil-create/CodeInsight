#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    string s;
    cin >> s;
    int mon = (s[5]-'0')*10 + (s[6]-'0');
    int day = (s[8]-'0')*10 + (s[9]-'0');
    if (mon > 4) cout << "TBD" << endl;
    else cout << "Heisei" << endl;
    return 0;
}