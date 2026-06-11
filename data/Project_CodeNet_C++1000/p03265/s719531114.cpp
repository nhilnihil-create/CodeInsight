#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int dx = x2 - x1;
    int dy = y2 - y1;
    cout << x2-dy << ' ' << y2+dx << ' ' << x2-dy-dx << ' ' << y2+dx-dy << '\n';
}