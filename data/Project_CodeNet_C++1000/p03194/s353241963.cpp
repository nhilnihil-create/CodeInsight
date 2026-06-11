#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
    long long n, p;
    cin >> n >> p;

    if (n == 1) {
        cout << p << endl;
        return 0;
    }

    vector<pair<long long, long long> > v;

    for (long long i = 2; i * i <= p; i++) {
        long long count = 0;
        while (p % i == 0) {
            count++;
            p /= i;
        }
        if (count) {
            v.push_back(make_pair(i, count));
        }
        if (i != 2) {
            i++;
        }
    }

    long long ans = 1;
    for (long long i = 0; i < v.size(); i++) {
        ans *= pow(v[i].first, v[i].second / n);
    }

    cout << ans << endl;

    return 0;
}
