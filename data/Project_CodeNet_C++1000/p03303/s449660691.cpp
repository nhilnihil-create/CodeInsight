#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>

using namespace std;

const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)

int main() {
    string S;
    int w;
    cin >> S >> w;
    string ans;
    for (int i = 0; i < S.length(); ++i) {
        if (i % w == 0) {
            ans += S[i];
        }
    }
    cout << ans << endl;
}
