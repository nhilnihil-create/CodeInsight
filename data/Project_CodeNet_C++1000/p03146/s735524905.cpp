#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int s;
    cin >> s;
    vector<int> id(1e6, -1);
    int len = 1;
    while (id[s] == -1) {
        len++;
        id[s] = len;
        if (s%2 == 0) s /= 2;
        else s = 3*s+1;
    }
    cout << len << endl;
    return 0;
}