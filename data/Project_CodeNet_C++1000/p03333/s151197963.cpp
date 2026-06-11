#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> l, vector<int> r) {
    long long ans = 0, sum = 0;
    while (!l.empty()) {
        auto x = l.back(); l.pop_back();
        sum += x; ans = max(ans, sum);
        if (!r.empty()) {
            auto y = r.back(); r.pop_back();
            sum += y; ans = max(ans, sum);
        }
        else break;
    }
    return ans;
}


int main() {
    int n; scanf("%d", &n);

    vector<int> l,r;
    while (n--) {
        int x,y; scanf("%d %d", &x, &y);
        l.push_back(x);
        r.push_back(-y);
    }
    sort(l.begin(), l.end()); 
    sort(r.begin(), r.end());
    cout << 2*max(solve(l,r), solve(r,l)) << endl;

    return 0;
}
