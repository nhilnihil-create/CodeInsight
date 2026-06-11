#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 50005

int main()
{
    _FastIO;

    char c[10][10];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        cout << c[i][i];
    }
    cout << endl;

    return 0;
}
