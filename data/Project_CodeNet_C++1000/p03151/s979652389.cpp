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
    int n;
    cin >> n;
    vector<ll> A(n, 0);
    vector<ll> B(n, 0);
    for(auto& val: A)
        cin >> val;
    for(auto& val: B)
        cin >> val;
    ll acc_a = accumulate(A.begin(), A.end(), 0LL);
    ll acc_b = accumulate(B.begin(), B.end(), 0LL);
    if (acc_a < acc_b) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> diff(n, 0);
    for(int i = 0; i < n; i++) {
        diff[i] = (A[i]-B[i]);
    }
    sort(diff.begin(), diff.end());
    int l = 0, r = n-1;
    ll balance = 0;
    
    while(diff[l] < 0) {
        balance += diff[l++];
        while(balance < 0) {
            balance += diff[r--];
        }
    }
    // cout << "l = " << l << ", r = " << r << endl;
    cout << (l+(n-1-r)) << endl;
    return 0;
}
