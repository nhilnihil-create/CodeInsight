#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> flag(100);
    for ( int i = 1; i <= n; i++)
    {
        int d;
        cin >> d;
        flag[d-1] = 1;
    }
    int out = 0;
    for(int i = 0; i <100; i++)
    {
        out += flag[i];
    }
    cout << out << endl;
}