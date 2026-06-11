#include <bits/stdc++.h>

using namespace std;

int main()
{
    string c1,c2,c3;
    cin >> c1 >> c2 >> c3;
    cout << c1.substr(0,1)+c2.substr(1,1)+c3.substr(2,1) << endl;
}