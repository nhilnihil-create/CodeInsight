#include <bits/stdc++.h>
using namespace std;
const int p = 6;
const int MAX = 30000;

int main() {
    int n;
    cin >> n;
    if (n < p) {
        if (n == 3) printf("2\n5\n63\n");
        if (n == 4) printf("2\n5\n20\n63\n");
        if (n == 5) printf("2\n5\n20\n30\n63\n");
        return 0;
    }
    
    vector<int> id(p, 0);
    vector<vector<int>> num(p);
    for (int i = 2; i <= MAX; i++) num[i%p].push_back(i);
    
    set<int> ans;
    for (int i = 2, _ = 0; _ < n; _++) {
        ans.insert(num[i][id[i]++]);
        if (i == 0) i = 2;
        else if (i == 2) i = 3;
        else if (i == 3) i = 4;
        else i = 0;
    }
    
    long long sum = 0;
    for (const auto& e : ans) sum += e;
    if (sum % p == 2) {
        ans.erase(8); ans.insert(num[0][id[0]]);
    } else if (sum % p == 3) {
        ans.erase(9); ans.insert(num[0][id[0]]);
    } else if (sum % p == 5) {
        ans.erase(9); ans.insert(num[4][id[4]]);
    }
    
    for (const auto& e : ans) cout << e << endl;
    return 0;
}