#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    vector<int> nums;
    int now = 1;
    int cnt = 0;
    rep(i, N){
        if(S.at(i) == (char)('0' + now)) cnt++;
        else {
            nums.push_back(cnt);
            now ^= 1;
            cnt = 1;
        }
    }
    if(cnt != 0) nums.push_back(cnt);
    if(nums.size() % 2 == 0) nums.push_back(0);

    int Add = 2 * K + 1;

    int ans = 0;
    for(int i = 0; i < nums.size(); i += 2){
        int tmp = 0;
        int left = i;
        int right = min(i + Add, (int)nums.size());
        for(int j = left; j < right; j++){
            tmp += nums.at(j);
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}