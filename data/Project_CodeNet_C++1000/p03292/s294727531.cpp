#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 

int main() {
    vector<int>a(3);
    rep(i,3)cin >>a[i];
    sort(a.begin(),a.end());
    cout << a[1]-a[0] + a[2]-a[1] <<endl;
    
 }
