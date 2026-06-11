#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    int blackH, blackW;
    cin >> blackH >> blackW;

    cout << (h - blackH) * (w - blackW) << endl;
}