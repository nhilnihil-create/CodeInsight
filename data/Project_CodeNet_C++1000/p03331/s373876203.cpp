#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int digit_sum(int n){
    int ret = 0;
    while(n > 0){
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 1e9;
    int n;
    cin >> n;
    for(int a = 1;a < n;a++){
        int b = n - a;
        ans = min(ans, digit_sum(a) + digit_sum(b));
    }
    cout << ans << endl;
    return 0;
}
