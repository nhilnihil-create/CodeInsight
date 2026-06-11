#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    for (int i=a; i<a+k; i++) {
        if (i > b) break;
        cout << i << '\n';
    }
    for (int i=b-k+1; i<=b; i++) {
        if (i < a+k) continue;
        cout << i << '\n';
    }
    
    return 0;
}