#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int N, M, X; cin >> N >> M >> X;
    set<int> A;
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        A.insert(a);
    }
    int left = 0, right = 0;
    for (int i = X; i <= N; i++) {
        if (A.count(i)) right++;
    }
    for (int i = X; i >= 0; i--) {
        if (A.count(i)) left++;
    }
    cout << min(left, right) << endl;
}