#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

int main(){
    int N, H, W;
    cin >> N >> H >> W;
    cout << (N - H + 1) * (N - W + 1) << endl;
    return 0;
}
