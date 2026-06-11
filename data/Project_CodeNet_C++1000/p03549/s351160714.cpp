/**
*    author:  souzai32
*    created: 01.08.2020 20:58:19
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    cout << (1900*m+100*(n-m))*pow(2,m) << endl;

    return 0;
}