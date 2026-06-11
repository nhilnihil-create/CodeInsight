#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int b = 0;
    int sum = 0;
    rep(j,n){
        cin >> a[j];
        sum += abs(a[j] - b);
        b = a[j];
    }
    sum += abs(0 - b);
    a.push_back(0);
    reverse(a.begin(), a.end());
    a.push_back(0);
    reverse(a.begin(), a.end());
    for (int j = 1;j<=n;j++){
        int ret = sum;
        ret -= abs(a[j] - a[j - 1]);
        ret -= abs(a[j] - a[j + 1]);
        ret += abs(a[j + 1] - a[j - 1]);
        cout << ret << endl;
    }
}