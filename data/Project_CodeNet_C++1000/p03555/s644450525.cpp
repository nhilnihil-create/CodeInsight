#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 3e5 + 5;
int main() {
    abdelrahman010
    char a[2][3];
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 3;j++)
            cin >> a[i][j];
    if(a[1][2] == a[0][0] && a[0][1] == a[1][1] && a[0][2] == a[1][0])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}