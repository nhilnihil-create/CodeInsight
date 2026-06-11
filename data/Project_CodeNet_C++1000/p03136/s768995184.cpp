#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int, int>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPU(i, a, b, s) for(int i = a; i < b; i += s)
#define REPD(i, a, b, s) for(int i = a; i > b; i -= s)
#define endl "\n"

ll INF = 2e18;
ll MOD = 1e9 + 7;
int i, j, k, t;

int main() {
    int N;
    cin >> N;

    vector<int> L(N);
    REP(i, N) { cin >> L[i]; }

    vector<int>::iterator it = max_element(L.begin(), L.end());
    int max_num = *it;
    int max_index = distance(L.begin(), it);
    int non_max_sum = 0;

    REP(i, N) {
        if(i != max_index) {
            non_max_sum += L[i];
        }
    }

    if(max_num < non_max_sum) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}