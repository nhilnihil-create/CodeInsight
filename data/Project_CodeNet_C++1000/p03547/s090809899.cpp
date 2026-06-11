#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    char X, Y;
    cin >> X >> Y;
    cout << (X > Y ? ">" : ((X == Y) ? "=" : "<")) << endl;
}