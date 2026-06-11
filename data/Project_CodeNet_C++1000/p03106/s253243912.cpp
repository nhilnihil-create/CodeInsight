#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> divisors(int n)
{
    vector<int> ret;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (n / i != i)
                ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> aNum = divisors(a);
    vector<int> bNum = divisors(b);
    vector<int> inter;
    set_intersection(aNum.begin(), aNum.end(), bNum.begin(), bNum.end(), back_inserter(inter));

    sort(inter.begin(), inter.end(), greater<int>());
    cout << inter[k - 1] << endl;
    return 0;
}