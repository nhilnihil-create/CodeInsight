#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int cal_xor(int x) {
    if (x % 4 == 0)
        return 0;
    else if (x % 4== 1)
        return 1;
    else if (x % 4 == 2)
        return x+1;
    return 0;
}

int main() {
    int m, k;
    cin >> m >> k;
    if (k >= (1<<m)) {
        cout << -1 << endl;
    } else {
        if (k == 0) {
            for(int i = 0; i < (1<<m); i++)
                cout << i << " " << i << " ";
            return 0;
        }
        int xor_all = cal_xor((1<<m)-1);
        int other = xor_all ^ k;
        if (other != k) {
            cout << -1 << endl;
        } else {
            vector<int> arr;
            for(int i = 0; i < (1<<m); i++) {
                if (i == k) continue;
                arr.push_back(i);
            }
            arr.push_back(k);
            for(int i = (1<<m)-1; i>= 0; i--) {
                if (i == k) continue;
                arr.push_back(i);
            }
            arr.push_back(k);
            for(int val: arr)
                cout << val << " ";
        }
    }
    return 0;
}

