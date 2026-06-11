#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
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
    vector<int> arr(n, 0);
    for(int& val: arr)
        cin >> val;
    vector<int> ans;
    while(!arr.empty()) {
        bool found = false;
        for(int i = arr.size()-1; i >= 0; i--) {
            if (arr[i] == i+1) {
                ans.push_back(arr[i]);
                for(int j = i; j < arr.size()-1; j++) {
                    arr[j] = arr[j+1];
                }
                arr.pop_back();
                found = true;
                break;
            }
        }
        if (!found && !arr.empty()) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for(int val: ans)
        cout << val << endl;
    return 0;
}


