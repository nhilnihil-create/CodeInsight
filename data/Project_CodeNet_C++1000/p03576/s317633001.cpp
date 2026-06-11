#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int n, k, x, y;
    vector<vector<ll>> arr;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end());
    ll area = ll(INT_MAX) * ll(INT_MAX-2);
    // cout << area << endl;
    for(int i = 0; i < n; i++) {
        for(int j = i+k-1; j < n; j++) {
            if (j-i+1 < k) continue;
            vector<int> ys;
            for(int k2 = i; k2 <= j; k2++)
                ys.push_back(arr[k2][1]);
            sort(ys.begin(), ys.end());
            // cout << ys.size() << endl;
            // cout << arr[i][0] << "~" << arr[j][0] << endl;
            ll width = llabs(arr[j][0]-arr[i][0]);
            for(int yy = 0; yy <= ys.size()-k; yy++) {
                //cout << ys[yy] << "~y " << ys[yy+k-1] << endl;
                //cout << "area " << width*llabs(ys[yy+k-1]-ys[yy]) << endl;
                area = min(area, width*llabs(ys[yy+k-1]-ys[yy]));
            }
        }
    }
    cout << area << endl;
    return 0;
}


