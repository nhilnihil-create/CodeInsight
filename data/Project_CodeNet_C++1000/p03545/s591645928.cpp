#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <bitset>
#include <map>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

using namespace std;

string result = "";

bool loopdfs(vector<int> & nums, int N, int sum) {
    if (N == 4) {
        if (sum != 7) return false;
        result = "=7";
        return true;
    }
    if (loopdfs(nums, N + 1, sum + nums[N])) {
        result = to_string(nums[N]) + result;
        if (N != 0) result = "+" + result;
        return true;
    }
    if (loopdfs(nums, N + 1, sum - nums[N])) {
        result = to_string(nums[N]) + result;
        if (N != 0) result = "-" + result;
        return true;
    }
    return false;
}

int main()
{
    string S;
    vector<int> nums(4);
    cin >> S;
    rep(i, 4) {
        nums[i] = (int)(S[i] - '0');
    }
    loopdfs(nums, 0, 0);
    cout << result << endl;
}