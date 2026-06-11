#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    /* しゃくとり法 */
    long long res = 0;
    int right = 0;
    int sum = 0; // AND 和
    for (int left = 0; left < n; ++left) {
        while (right < n && (sum ^ a[right]) == (sum + a[right])) {
            sum += a[right];
            ++right;
        }
        res += right - left;
        //if (left == right) ++right;
        //else {
            sum -= a[left]; // a[left] を削除 (sum ^= a[left] でも OK)
        //}
    }
    
    cout << res << endl;
}
