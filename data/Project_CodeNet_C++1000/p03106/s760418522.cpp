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
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = min(a,b); i >= 1; i--) {
        if (a%i == 0 && b%i == 0) k--;
        if (k == 0) {
            cout << i << endl; 
            return 0;
        }
    }
    return 0;
}