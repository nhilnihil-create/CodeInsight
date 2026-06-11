#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 99999999
using namespace std;

int main() {
    long long n, ans = 0;
    cin >> n;
    vector <vector<long long>> v(n, vector<long long>(3));
    long long a, b, c;
    for (vector<long long>& tmp : v) {
        cin >> a >> b;
        c = a+b;
        tmp[0] = c; tmp[1] = a; tmp[2] = b;
        ans -= b;
    }
    /*
    for(vector<long long> tmp : v) {
        cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
    }
     */
    sort(v.begin(), v.end(), greater<>());
    for(long long i = 0; i < n; i += 2) {
        ans += v[i][0];
    }
    cout << ans << endl;
    return 0;
}
