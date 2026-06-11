#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    int A, B, K;
    cin >> A >> B >> K;

    int count = 0;

    int maxRep = max(A, B);

    vector<int> v = vector<int>();

    rep(i, maxRep + 1)
    {
        if (i == 0)
        {
            continue;
        }

        if (A % i == 0 && B % i == 0)
        {
            v.push_back(i);
        }
    }

    std::cout << v.at(v.size() - K) << endl;

    return 0;
}
