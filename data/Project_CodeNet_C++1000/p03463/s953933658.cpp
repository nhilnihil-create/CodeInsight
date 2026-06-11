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
    int n, a, b;
    cin >> n >> a >> b;
    if ((a+b) % 2 == 0) {
        cout << "Alice" << endl;
    } else {
        cout << "Borys" << endl;
    }
    return 0;
}
