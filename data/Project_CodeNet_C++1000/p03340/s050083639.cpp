#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int i = 0, j = 0, x = 0;
    long long res = 0;
    while(i < n) {
        while(j < n && (x&a[j]) == 0) {
            x += a[j];
            j++;
        }
        res += j - i;
        if(i == j) j++;
        else x -= a[i];
        i++;
    }
    cout << res << endl;
    return 0;
}