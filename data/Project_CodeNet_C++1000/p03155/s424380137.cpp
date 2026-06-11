#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main(void) {
    int n, h, w;
    cin >> n >> h >> w;
    cout << (n - h + 1) * (n - w + 1) << endl;
    return 0;
}