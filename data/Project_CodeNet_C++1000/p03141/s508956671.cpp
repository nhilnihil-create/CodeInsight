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
    ll a, b;
    cin >> n;
    vector<vector<ll>> arr;
    for(int i =0; i < n; i++) {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), [](vector<ll> pre, vector<ll> post){
        return pre[0] + pre[1] > post[0] + post[1];
    });
    ll bob = 0, alice = 0;
    for(int i = 0; i < n; i+= 2)
        bob += arr[i][0];
    for(int i = 1; i < n; i+= 2)
        alice += arr[i][1];
    cout << bob - alice << endl;
    return 0;
}


