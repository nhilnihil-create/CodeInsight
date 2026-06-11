#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n,sum = 0;
    cin >> n;
    bitset<4000010> dp[2];
    dp[0].reset();
    dp[1].reset().set(0);
    for (int i = 0;i < n;++i) {
        int a;
        cin >> a;
        sum += a;
        dp[i&1] = dp[(i&1)^1];
        dp[i&1] |= (dp[(i&1)^1]<<a);
    }
    for (int i = (sum+1)/2;i < 4000010;++i) if (dp[(n&1)^1][i]) {
        cout << i << endl;
        break;
    }
    return 0;
}