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
    int X; cin >> X;
    int n = sqrt(X);
    vector<int> bekijo;
    bekijo.push_back(1);
    for (int i = 2; i <= n; i++) {
        int j = 2, num = 1;
        while  (num * i <= X) {
            num *= i;
            j++;
            bekijo.push_back(num);
        }
    }
    sort(bekijo.begin(), bekijo.end());
    cout << bekijo.at(bekijo.size() - 1) << endl;
}