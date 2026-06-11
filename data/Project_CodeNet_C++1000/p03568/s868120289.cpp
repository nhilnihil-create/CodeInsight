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
    int n, val;;
    cin >> n;
    ll total = 1, odd = 1;
    for(int i = 0; i < n; i++) {
        cin >> val;
        if (val % 2 == 0)
            odd *= 2;
        total *= 3;
    }
    cout << total - odd << endl;
    return 0;
}
