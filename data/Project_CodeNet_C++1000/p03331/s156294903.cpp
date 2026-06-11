#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
#define MAX 10000000000
#define rep(i,n) for(int i = 0; i < n;i++)
ll v, n, c, e, u, k, ans = MAX,sum;
int digsum(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int main(void) {
	int n, a, b;cin >> n;
    for(int i = 1;i < n;i++) {
        a = i;b = n - i;
        sum = digsum(a) + digsum(b);
        ans = min(sum, ans);
    }
    cout << ans << endl;
}