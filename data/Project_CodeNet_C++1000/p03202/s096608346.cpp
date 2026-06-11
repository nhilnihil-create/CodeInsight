#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
#define REP(i, x, y) for(ll i = x; i < y; i++)
#define PER(i, x, y) for(ll i = x; i > y; i--)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-11;

void normalize(vector<plglg> &nums) {
    ll len = nums.size();
    if (len > 1) {
        if (nums[len - 1].first == nums[len - 2].first) {
            nums[len - 2].second += nums[len - 1].second;
            nums.pop_back();
        }
    }
}

void add(vector<plglg> &nums) {
    if (nums.back().second == 1) {
        nums.back().first += 1;
    } else {
        nums.back().second--;
        nums.push_back(plglg(nums.back().first + 1, 1));
    }
    normalize(nums);
}

int main() {
    ll N;
    cin >> N;
    ll A[N];
    REP(i, 0, N) {
        cin >> A[i];
    }
    ll hi = 200010;
    ll lo = 0;
    while (hi - lo > 1) {
        ll mid = (hi + lo) / 2;
        bool ok = true;
        vector<plglg> nums;
        nums.push_back(plglg(0, A[0]));
        REP(i, 1, N) {
            if (A[i] > A[i - 1]) {
                nums.push_back(plglg(0, A[i] - A[i - 1]));
            } else {
                ll sum = 0;
                while (nums.size() > 0 && sum + nums.back().second <= A[i - 1] - A[i]) {
                    sum += nums.back().second;
                    nums.pop_back();
                }
                nums.back().second -= A[i - 1] - A[i] - sum;
                if (nums.back().first == mid - 1) {
                    if (nums.size() == 1) {
                        ok = false;
                        break;
                    } else {
                        ll num = nums.back().second;
                        nums.pop_back();
                        add(nums);
                        nums.push_back(plglg(0, num));
                    }
                } else {
                    add(nums);
                }
                normalize(nums);
            }
        }
        if (ok) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << endl;
}
