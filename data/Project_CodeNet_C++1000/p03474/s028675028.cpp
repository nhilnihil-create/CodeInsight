// https://atcoder.jp/contests/abc084/tasks/abc084_b
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int A, B;
    string S;
    cin >> A >> B >> S;
    REP(i, A)
    {
        if (S[i] == '-')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    if (S[A] != '-')
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = A + 1; i < A + B + 1; ++i)
    {
        if (S[i] == '-')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
