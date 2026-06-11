#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    string n;
    cin >> n;
    rep(i, n.size()){
        if(n[i] == '9') n[i] = '1';
        else n[i] = '9';
    }
    cout << n << endl;
    return 0;
}