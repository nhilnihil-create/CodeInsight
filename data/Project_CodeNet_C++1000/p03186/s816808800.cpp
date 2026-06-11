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
#define rep(i,n) for(int i = 0; i < n;i++)
ll d[300][300],v, n, c, e, u, k, sum = 0,ans;
int main(void) {
    ll a, b, c, sum = 0;
    cin >> a >> b >> c;
    if (a + b + 1 < c) {
        cout << a + b + 1 + b << endl;
    }
    else cout << b + c << endl;
}