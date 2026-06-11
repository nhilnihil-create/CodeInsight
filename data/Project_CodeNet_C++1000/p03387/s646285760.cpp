/**
*    created: 12.05.2020 08:48:37
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    int a[3];
    rep(i,3) cin>>a[i];
    sort(a, a+3);
    int x = a[0] + a[2] - a[1]; //上の操作後の値
    if((a[2]-x)%2)
        x = (a[2] - x) / 2 + 2;
    else
        x = (a[2] - x) / 2;
    int ans =  a[2] - a[1] + x;
    cout << ans << endl;
}