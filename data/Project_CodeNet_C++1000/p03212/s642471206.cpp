#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int N;
int numbers[3] = {3, 5, 7};
int ok = ((1 << 3) | (1 << 5) | (1 << 7));

int dfs(int num, int sz, int lim, int stat) {
    // cout << "# num : " << num << " sz : " << sz << " stat : " << stat << " N : " << N << endl;
    if (num > N) return 0;

    int count = 0;
    if (sz > 0 && num <= N && stat == ok) count++;
    if (sz == lim) return count;

    REP(i, 0, 3) {
        count += dfs(num * 10 + numbers[i], sz + 1, lim, stat | (1 << numbers[i]));
    }
    return count;
}

int main() {
    cin >> N;
    cout << dfs(0, 0, log10(N) + 1, 0) << endl;
    return 0;
}