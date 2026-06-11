#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a, b;

int main()
{
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    long long sum = 0;
    for (int digit=0; digit<28+1; digit++)
    {
        // (digit桁目を求める)
        vector<long long> btrunc = b;
        for (auto &i : btrunc)
        {
            i = i & ((1<<(digit+1))-1);
        }
        sort(btrunc.begin(), btrunc.end());

        long long ans = 0;
        for (auto ai : a)
        {
            long long atmp = ai & ((1<<(digit+1))-1);
            ans += distance(lower_bound(btrunc.begin(), btrunc.end(), (1<<(digit))*1-atmp), lower_bound(btrunc.begin(), btrunc.end(), (1<<(digit))*2-atmp));
            ans += distance(lower_bound(btrunc.begin(), btrunc.end(), (1<<(digit))*3-atmp), lower_bound(btrunc.begin(), btrunc.end(), (1<<(digit))*4-atmp));
            ans = ans % 2;
        }
        sum += ans << digit;
    }
    cout << sum << endl;
    return 0;
}