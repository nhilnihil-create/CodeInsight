#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(a, b) << " " << max(0, a+b-n) << endl;
    return 0;
}


