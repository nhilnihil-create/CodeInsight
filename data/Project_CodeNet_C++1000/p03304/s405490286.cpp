#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

// case len2
//1~4
//0: 11 22 33 44
//1: 12 21 23 32 34 43
//2: 13 31 24 42
//3: 14 41

//n^2
//n, (n-1)*2, (n-2)*2 + (n-3)*2
//n(n-1)
int main() {
    ll n, m, d;
    cin >> n >> m >> d;

    ll cnt_between2 = (d == 0) ? n: (n-d) * 2;
    double acc = double(cnt_between2)/n * (m-1);
    acc /= n;
    cout << fixed << setprecision(12) << acc << endl;
    return 0;
}

