#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    long n, h;
    cin >> n >> h;
    vector<long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(a, greater<long>());
    sort(b, greater<long>());
    long atk = 0;
    while (atk < n && a[0] < b[atk] && 0 < h) h -= b[atk++];
    if (0 < h) atk += (h + a[0] - 1) / a[0];
    cout << atk << endl;
}
