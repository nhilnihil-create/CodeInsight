/**
*    created: 16.05.2020 08:02:14
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    string c1, c2;
    cin >> c1 >> c2;
    reverse(c1.begin(), c1.end());
    if(c1==c2) cout << "YES" << endl;
    else cout << "NO" << endl;
}