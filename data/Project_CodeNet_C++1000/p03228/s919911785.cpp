#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    // 操作回数がK<=100なのでシミュレーションで間に合う
    vector<int> cookies(2);
    int K;
    cin >> cookies[0] >> cookies[1] >> K;
    for (int i = 0; i < K; ++i)
    {
        int first = i % 2 == 0 ? 0 : 1;
        int second = i % 2 == 0 ? 1 : 0;
        if (cookies[first] % 2 == 1) --cookies[first];
        cookies[first] /= 2;
        cookies[second] += cookies[first];
    }
    cout << cookies[0] << ' ' << cookies[1] << endl;
}
