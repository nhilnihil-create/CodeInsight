#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;
int main() {
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) cin >> a.at(i);

    int sum = 0;
    long long ans = 0;
    int right = 0;
    for(int left = 0; left < n; ++left) {
        while(right < n && (sum ^ a.at(right)) == (sum + a.at(right))) {
            sum += a.at(right);
            ++right;
        }

        ans += right - left;
        if(left == right) ++right;
        else {
            sum -= a.at(left);
        }
    }

    cout << ans << endl;
}