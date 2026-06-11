#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main(void)
{   
    int n;
    cin >> n;

    vector<int> p(n);
    int nmax = 0;
    int sum = 0;
    rep(i, n) {
        cin >> p[i];
        sum += p[i];
        nmax = max(nmax, p[i]);
    }

    cout << sum - nmax/2 << endl;
    return 0;
}