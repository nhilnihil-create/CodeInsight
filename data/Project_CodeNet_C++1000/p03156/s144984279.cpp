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
ll p[25];
int main(void) {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int first = 0;
    int second = 0;
    int third = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] <= a) {
            first++;
        }
        if (p[i] >= a + 1 && p[i] <= b) {
            second++;
        }
        if (p[i] >= b + 1) {
            third++;
        }
    }
    cout << min({ first,second,third }) << endl;
    return 0;
}