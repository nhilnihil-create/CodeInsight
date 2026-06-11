#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main()
{
    long long int n, p;
    long long int cnt[1000010] = {0};
    long long int ans = 1;
    map<long long int, long long int> mp;

    cin >> n >> p;

    long long int tmp = p;

    for (int i = 2; i < sqrtl(tmp); i++) {
        if (p % i == 0) {
            while (p % i == 0) {
                p /= i;
                mp[i]++;
            }
        }
    }
    mp[p] = 1;

    for (auto x: mp) {
        if (n <= x.second) {
            while (n <= x.second) {
                ans *= x.first;
                x.second -= n;
            }
        }
    }

    cout << ans << endl;
}
