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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a+b > c+d)
        cout << "Left" << endl;
    else if (a+b == c+d)
        cout << "Balanced" << endl;
    else
        cout << "Right" << endl;
    return 0;
}
