#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n+1);
    rep(i, 0, m){
        int j;
        cin >> j;
        a[j]++;
    }
    int sum_1 = 0, sum_2 = 0;
    rep(i, 0, x){
        if(a[i]) sum_1++;
    }
    rep(i, x, n){
        if(a[i]) sum_2++;
    }
    cout << min(sum_1, sum_2) << endl;
    return 0;
    
}
