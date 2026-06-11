#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int k = 0;
    while(k * (k + 1) / 2 < n) {
        k++;
    }
    if(k * (k + 1) / 2 != n) {
        cout << "No";
        return 0;
    }
    k++;
    vector < vector <int> > sol;
    sol.resize(k + 1);
    cout << "Yes" << "\n" << k << "\n";
    int cur = 0;
    for(i = 1; i < k; i++) {
        for(j = i + 1; j <= k; j++) {
            sol[i].push_back(++cur);
            sol[j].push_back(cur);
        }
    }
    for(i = 1; i <= k; i++) {
        cout << sol[i].size() << " ";
        for(auto it : sol[i]) {
            cout << it << " ";
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}
