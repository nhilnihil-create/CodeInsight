#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
#define pll pair<ll, ll>

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    vector<ll> nums = {A, B, C};
    if (K == 0) {
        cout << A - B << endl;
        return 0;
    }

    ll na = nums[1] + nums[2];
    ll nb = nums[0] + nums[2];
    ll nc = nums[0] + nums[1];
    nums[0] = na;
    nums[1] = nb;
    nums[2] = nc;
    if (abs(nums[0] - nums[1]) > (ll)pow(10, 18))
        cout << "Unfair" << endl;
    else {
        if (K % 2 == 1)
            cout << nums[0] - nums[1] << endl;
        else
            cout << nums[1] - nums[0] << endl;
    }
}