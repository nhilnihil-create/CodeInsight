#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
using namespace std;

#define NMAX 21

vector <tuple <int, int, int> > sol;

int main()
{
    ios::sync_with_stdio(false);

    int l;
    // ifstream cin("code.in");
    cin >> l;

    int k = 1;
    while ((1 << k) - 1 < l) {
        k++;
    }

    for (int i = 1; i < k; i++) {
        sol.emplace_back(i, i + 1, 0);
        sol.emplace_back(i, i + 1, 1 << (i - 1));
    }

    int sum = (1 << (k - 1));
    for (int i = k - 1; i >= 1; i--) {
        if ((l & (1 << (i - 1))) == 0)
            continue;
        sol.emplace_back(i, k, sum);
        sum += (1 << (i - 1));
    }

    cout << k << " " << sol.size() << "\n";
    for (const tuple <int, int, int>& x : sol) {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << '\n';
    }
    return 0;
}
