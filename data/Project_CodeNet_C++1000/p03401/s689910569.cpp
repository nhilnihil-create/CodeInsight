#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int N; cin >> N;
    vector<int> A(N);
    A.push_back(0);
    int sum = 0;
    for (int i = 1; i < N + 1; i++) {
        cin >> A.at(i);
        sum += abs(A.at(i) - A.at(i - 1));
    }
    sum += abs(A.at(N));
    A.push_back(0);
    for (int i = 1; i < N + 1; i++) {
        int disap = abs(A.at(i) - A.at(i - 1)) + abs(A.at(i + 1) - A.at(i));
        int appea = abs(A.at(i + 1) - A.at(i - 1));
        cout << sum - disap + appea << endl;
    }
    return 0;
}