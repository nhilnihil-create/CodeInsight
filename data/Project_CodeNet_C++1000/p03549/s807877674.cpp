#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n,m;//m<=min(n,5)
    cin >> n >> m;

    int ans = 0;

    int step = 1900 * m + (n-m) * 100;

    cout << step * pow(2,m) << endl;
}   
