#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

using ll = long long;
using P = pair<ll, ll>;

/*追加部分*/

int sum_digit(int _num){
    int a = _num / 10000;
    int b = _num%10000 / 1000;
    int c = _num%1000 / 100;
    int d = _num%100 / 10;
    int e = _num%10;

   return a + b + c + d + e;
}

/*main関数*/

int main() {
FASTIO;
    int n, a, b; cin >> n >> a >> b;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a <= sum_digit(i) && sum_digit(i) <= b){
            ans += i;
        }
    }
    cout << ans << endl;

return 0;
}