#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n;
    string A, B, C;
    cin >> n >> A >> B >> C;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        unordered_map<char, int> cnt;
        cnt[A[i]] += 1;
        cnt[B[i]] += 1;
        cnt[C[i]] += 1;
        ans += cnt.size()-1;
    }
    cout << ans << endl;

    return 0;
}

