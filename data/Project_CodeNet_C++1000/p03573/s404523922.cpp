#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int a, b, c;
    cin >> a >> b >>c;
    if(a-c == 0){
        cout << b << endl;
        return 0;
    }
    if(b-c == 0){
        cout << a << endl;
        return 0;
    }
    if(a-b == 0){
        cout << c << endl;
        return 0;
    }
}