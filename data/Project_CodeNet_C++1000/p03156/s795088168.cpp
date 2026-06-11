#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n, a, b, val;
    cin >> n >> a >> b;
    vector<int> ans(3, 0);
    for(int i = 0; i < n; i++) {
        cin >> val;
        if (val <= a)
            ans[0] += 1;
        else if (val <= b)
            ans[1] += 1;
        else
            ans[2] += 1;
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
    return 0;
}
