#include <bits/stdc++.h>
using namespace std;
void make_v(vector<int> &v, int a, int b, int c) {
    for (int i = 0; i < a; i++) v.push_back(3);
    for (int i = 0; i < b; i++) v.push_back(5);
    for (int i = 0; i < c; i++) v.push_back(7);
}
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 3; i < 10; i++) {
        for (int a = 1; a <= i - 2; a++) {
            for (int b = 1; a + b <= i - 1; b++) {
                int c = i - a - b;
                vector<int> v;
                make_v(v, a, b, c);
                do {
                    int n = 0;
                    for (auto u: v) n = n * 10 + u;
                    nums.push_back(n); 
                } while (next_permutation(v.begin(), v.end()));
            }
        }
    }
    // dfs({3, 5, 7});
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (auto x: nums) {
        if (x > n) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}