#include <bits/stdc++.h>

using namespace std;

int main() {
    string A, B, C, D, E;
    cin >> A;
    int ans=0;
    if (A.at(0)=='o')
    {
        ans++;
    }if (A.at(1)=='o')
    {
        ans++;
    }if (A.at(2)=='o')
    {
        ans++;
    }
    cout << 700+100*ans << endl;
    return 0;
}