#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;
int main() {
    long long n, m, a, b, c, d, i, j;
    cin >> n >> m;
    vector<long long> v[n];
    long long v2[m][2];

    for(i=0;i<m;i++) {
        cin >> a >> b;
        v[a-1].push_back(b);
        v2[i][0] = a-1;
        v2[i][1] = b;
    }

    for(i=0;i<n;i++) {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    for(i=0;i<m;i++) {
        long long city = v2[i][0];
        long long id = v2[i][1];
        long long id2 = distance(v[city].begin(), lower_bound(v[city].begin(), v[city].end(), id));
        printf("%06lld%06lld\n", city+1, id2+1);
    }
}